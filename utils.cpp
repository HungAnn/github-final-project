#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <experimental/filesystem>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>
namespace fs = std::experimental::filesystem;

using namespace cv;
using namespace std;

void parsArgs(int argc, char *argv[], bool *writeImg, vector<int> *boundaries)
{
    // printf(*writeImg ? "t" : "f");
    for (uint8_t i = 2; i < argc; i++)
    {
        if (static_cast<string>(argv[i]) == "-w")
        {
            *writeImg = true;
            cout << "Save the result images in this folder." << endl;
        }
        if (static_cast<string>(argv[i]) == "-b")
        {
            uint8_t bNumbers = argc - 1 - i;

            for (uint8_t j = 1; j <= bNumbers; j++)
            {
                boundaries->push_back(atoi(argv[i + j]));
                boundaries->push_back(255 - (*boundaries).back());
            }
        }
    }
    sort(boundaries->begin(), boundaries->end());
    cout << "Set the boundaries = ";
    for (int i = 0; i < boundaries->size(); i++)
    {
        cout << boundaries->at(i) << " ";
    }
    cout << endl;
}
string getImgName(string fullName)
{
    cout << "Input image: " << fullName << endl;
    size_t extendIndex = fullName.find_last_of(".");
    size_t pathIndex = fullName.find_last_of("/") + 1;
    string tmpImgName = fullName.substr(0, extendIndex);
    int tmpLen = tmpImgName.size();
    string rawImgName = tmpImgName.substr(pathIndex, -1);
    return rawImgName;
}

void getImgInfo(string name, Mat img)
{
    cout << name << "size: " << img.size() << ", channels: " << img.channels() << ", depth: " << img.depth() << endl;
}

void updateCount(int val, int count_, int countRegion[], vector<int> boundaries)
{
    if (val > boundaries.back())
    {
        countRegion[boundaries.size()] += count_;
    }
    else if (val < boundaries.front())
    {
        countRegion[0] += count_;
    }
    else
    {   
        for (int j = 1; j < boundaries.size(); j++)
        {
            if ((boundaries.at(j - 1) < val) && (val < boundaries.at(j)))
            {
                cout << boundaries.at(j - 1) << " " << boundaries.at(j) << " " << val << endl;
                countRegion[j] += count_;
                break;
            }
        }
    }
}

void calPercentage(string name, Mat lightHist, Mat img, int countRegion[], int regionNum, vector<int> boundaries, int histSize)
{
    int imgH = img.cols;
    int imgW = img.rows;
    float allPixels = imgH * imgW;

    for (int i = 0; i < histSize; i++)
    {
        updateCount(i, cvRound(lightHist.at<float>(i)), countRegion, boundaries);
    }

    cout << name << " Image:";
    for (uint32_t i = 0; i < regionNum; i++)
    {
        cout << "\nPercentage of region" << to_string(i + 1) << ": " << (float)countRegion[i] / allPixels * 100.0;
    }
    cout << endl;
}

void showHist(string name, Mat img, vector<int> boundaries, bool writeImg)
{
    int histSize = 256;
    float range[] = {0, 256}; //the upper boundary is exclusive
    const float *histRange[] = {range};
    bool uniform = true, accumulate = false;
    int scaleW = 3;
    int histW = 256 * scaleW;
    int histH = 600;
    Mat lightHist;
    int binW;
    int regionNum = boundaries.size() + 1;
    int countRegion[regionNum] = {0};

    calcHist(&img, 1, 0, Mat(), lightHist, 1, &histSize, histRange, uniform, accumulate);
    calPercentage(name, lightHist, img, countRegion, regionNum, boundaries, histSize);
    binW = cvRound((double)histW / histSize);
    Mat histImage(histH, histW, CV_8UC3, Scalar(0, 0, 0));
    normalize(lightHist, lightHist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 0; i < boundaries.size(); i++)
    {
        line(histImage, Point(boundaries[i] * scaleW, 0), Point(boundaries[i] * scaleW, histH), Scalar(0, 255, 0), 2, 8, 0);
    }
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(binW * (i - 1), histH - cvRound(lightHist.at<float>(i - 1))),
             Point(binW * (i), histH - cvRound(lightHist.at<float>(i))),
             Scalar(255, 255, 255), 2, 8, 0);
    }

    if (writeImg)
    {
        imwrite(name + "_Hist.png", histImage);
    }
    imshow(name + "Histogram", histImage);
}