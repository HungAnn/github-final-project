#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <ostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <regex>
#include <sstream>
#include <string>
#include <experimental/filesystem>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <chrono>
#include <ctime>

#include "utils.h"
namespace fs = std::experimental::filesystem;

using namespace cv;
using namespace std;
bool dirExists(std::string path);
int remove_directory(std::string pathS);
/*
./Demo /home/hungan/Downloads/image/RX300528.JPG -w -b 10
*/
void func(int a[], int c)
{
    // for (int i = 0; i < c; i++) {
    //     std::cout << a[i] << " ";
    // }
    a[1] += 112;
    a[0] += 1;
}
int main(int argc, char *argv[])
{
    // 111111111111111111111111111111111111111111111111111111111111111111111111
    // vector<int> a = {10, 20, 30};
    // for (int i = 1; i < a.size(); i++)
    // {
    //     if (a.at(i - 1) < b && b < a.at(i))
    //     {
    //         std::cout << i << " " << a.at(i - 1) << " " << a.at(i) << std::endl;
    //     }
    // }
    // if(b = a.at(1)){
    //     std::cout << a.at(1) << std::endl;
    // }

        if (argc < 2)
        {
            printf("usage: DisplayImage.out <Image_Path>\n");
            return -1;
        }
        Mat img;
        Mat resized_img;
        Mat hsl_img;
        Mat gray_img;
        Mat lightness;
        vector<Mat> channels;
        int height;
        int width;
        float resize_scale = 0.3;
        vector<int> boundaries;
        string fullName = argv[1];
        string imgName = getImgName(argv[1]);
        bool writeImg = false;

        parsArgs(argc, argv, &writeImg, &boundaries);

        //  Read and resize image
        img = imread(fullName);
        height = img.rows;
        width = img.cols;
        if (!img.data)
        {
            printf("No image data \n");
            return -1;
        }
        Size dsize = Size(round(resize_scale * width), round(resize_scale * height));
        resize(img, resized_img, dsize, 0, 0, INTER_AREA);

        //  Get Hls image
        cvtColor(img, hsl_img, COLOR_RGB2HLS);
        split(hsl_img, channels);
        lightness = channels[1].clone();
        getImgInfo("img", img);
        getImgInfo("hsl_img", hsl_img);
        getImgInfo("lightness", lightness);
        cout << endl;
        //  Get gray image
        cvtColor(img, gray_img, COLOR_RGB2GRAY);
    cout << "1" << endl;
    cout << "Set the boundaries b1,b2 = " << boundaries[0] << "," << boundaries[1] << endl;
        //  Show image
        // namedWindow("Resized Image", WINDOW_NORMAL);
        // imshow("Resized Image", resized_img);
        // namedWindow("Gray Image", WINDOW_NORMAL);
        // imshow("Gray Image", gray_img);
        // namedWindow("Lightness Image", WINDOW_NORMAL);
        // imshow("Lightness Image", lightness);
        //  Show histogram
        showHist(imgName + "_Lightness", lightness, boundaries, writeImg);
        showHist(imgName + "_Gray", gray_img, boundaries, writeImg);

        //  Save image
        if (writeImg)
        {
            imwrite(imgName + "_Gray_Image.png", gray_img);
            imwrite(imgName + "_Lightness_Image.png", lightness);
        }

        waitKey(0);
        return 0;
}

bool dirExists(std::string path)
{
    struct stat info;
    if (stat(path.c_str(), &info) == 0 && info.st_mode & S_IFDIR)
    {
        return true;
    }
    return false;
}
int remove_directory(std::string pathS)
{
    const char *path = pathS.c_str();
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d)
    {
        struct dirent *p;
        r = 0;
        while (!r && (p = readdir(d)))
        {
            int r2 = -1;
            char *buf;
            size_t len;

            /* Skip the names "." and ".." as we don't want to recurse on them. */
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2;
            buf = (char *)malloc(len);

            if (buf)
            {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf))
                {
                    if (S_ISDIR(statbuf.st_mode))
                        r2 = remove_directory(buf);
                    else
                        r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }

    if (!r)
        r = rmdir(path);

    return r;
}