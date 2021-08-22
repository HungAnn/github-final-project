#include <memory>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <sstream>
#include <string>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <sys/time.h>
#include <ctime>
#include <chrono>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#include "LogUtils.h"

using std::cout; using std::endl;
// #include "CRSDK/CameraRemote_SDK.h"
// #include "CameraDevice.h"
// namespace SDK = SCRSDK;
// #include "RemoteUtils.h"
// #include "histUtils.h"

// bool isStop = false;
// void getUserInput();
// std::string calFPS(int64_t, int64_t);
// bool drawText(cv::Mat, std::string);
// void getPercentage(int countRegion[]);
// std::string getCurrentT();

// void getImgInfo(std::string name, cv::Mat img);
// void parsArgs(int argc, char *argv[], vector<int> *boundaries);
// std::string parsISO(std::string isoStr);
// std::string getImgName(int imgCount, std::string imgPrefix, int zeroCapacity, std::string savePath, std::string imgExtend);
// template <typename T>
// size_t countDigits(T n);
// void resetPR(float percentRegion[]);
/*
./RemoteCli -b 10
*/
void func1()
{
    printf("originISO not in remoteUtils->isoOpts, set 3,200 \n");
}
void func2()
{
    printf("111");
}
int main(int argc, char *argv[])
{
    for(int i = 0; i<10000; i++)
    {
        if(i % 100 == 0)
        {
            std::cout << i << std::endl;
        }
    }
    // auto t1 = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1));
    // auto t2 = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    // std::cout << ms_double.count() << "ms";
    return 0;
}
//     std::string savePath = "";
//     rmUtils::RemoteUtils *remoteUtils = new rmUtils::RemoteUtils();
//     remoteUtils->initRemoteSDK();
//     remoteUtils->initCamera();
//     savePath = remoteUtils->setSaveInfo("image/" + getCurrentT(), true) + "/";
//     if (savePath == "Failed to set save path.")
//     {
//         remoteUtils->release();
//         return -1;
//     }
//     std::this_thread::sleep_for(std::chrono::milliseconds(3000));

//     //Adjust ISO
//     cv::Mat img;
//     cv::Mat lightness;
//     std::vector<int> boundaries;
//     std::string imgPrefix = "DSC";
//     std::string imgExtend = ".JPG";
//     int zeroCapacity = 4;
//     uint32_t imgCount = 0;
//     int adjustWT = 800;
//     int captureWT = 2000;

//     std::string originISO = remoteUtils->getISO();
//     if (remoteUtils->isoOpts.find(originISO) == remoteUtils->isoOpts.end())
//     {
//         printf("originISO not in remoteUtils->isoOpts, set 3,200 \n");
//         remoteUtils->setISO(remoteUtils->isoOpts["3,200"]);
//         originISO = "3,200";
//         std::this_thread::sleep_for(std::chrono::milliseconds(adjustWT));
//     }
//     uint8_t originISOIndex = remoteUtils->isoOpts[originISO];
//     uint8_t currentISOIndex = originISOIndex;
//     std::cout << "Original ISO: " << originISO << ", Index: " << std::to_string(originISOIndex) << std::endl;

//     parsArgs(argc, argv, &boundaries);
//     int regionNum = boundaries.size() + 1;
//     float percentRegion[regionNum] = {0};

//     std::thread userInputThread(getUserInput);
//     userInputThread.detach();
//     for (;;)
//     {
//         if (isStop)
//         {
//             std::cout << "User input to stop loop.\n";
//             break;
//         }
//         std::cout << "============================================" << std::endl;
//         imgCount += 1;
//         resetPR(percentRegion);
//         std::string imgName = getImgName(imgCount, imgPrefix, zeroCapacity, savePath, imgExtend);
//         remoteUtils->capture_Image(); ///////////////////////////////////////////////////
//         std::this_thread::sleep_for(std::chrono::milliseconds(captureWT));

//         img = cv::imread(imgName);
//         if (!img.data)
//         {
//             printf("No image data \n");
//             continue;
//             //remoteUtils->release();
//             //return -1;
//         }
//         getLightness(img, &lightness);
//         calPercentage(imgName, lightness, boundaries, percentRegion, true);

//         currentISOIndex = adjustAlg_1(percentRegion, currentISOIndex, remoteUtils);
//         remoteUtils->setISO(currentISOIndex);
//         std::this_thread::sleep_for(std::chrono::milliseconds(adjustWT));
//     }
//     // //LiveView
//     // double startTC, endTC;
//     // char stopChar;
//     // std::string fpsStr;
//     // cv::Mat image;
//     // std::string liveViewName = "LiveView000000.JPG";
//     // cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
//     // std::cout << "New a LiveView Window.\n";

//     // std::thread userInputThread(getUserInput);
//     // std::cout << "Start loop(press '0' to quit)\n";
//     // for (;;)
//     // {
//     // if(isStop){
//     //     std::cout << "User input to stop loop.\n";
//     //     break;
//     // }
//     //     //std::cout << "1\n";
//     //     double inferenceTime = 0.0;
//     //     double t1 = static_cast<double>(cv::getTickCount()); //startTC = (double)cv::getTickFrequency(); //get start tick count
//     //     //std::cout << "2\n";
//     //     remoteUtils->getLiveView();
//     // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     //     double t2 = static_cast<double>(cv::getTickCount()); //endTC = (double)cv::getTickFrequency(); //get end tick count
//     //     inferenceTime = (t2 - t1) / cv::getTickFrequency() * 1000;
//     //     std::string fpsStr;
//     //     fpsStr = "FPS: " +std::to_string(int(1000.0f / inferenceTime * 100) / 100.0f); //fpsStr = calFPS(startTC, endTC);
//     //     //std::cout << "3\n";
//     //     image = cv::imread(liveViewName, 1);
//     //     //std::cout << "4\n"; //
//     // std::cout << fpsStr << "\n";//drawText(image, fpsStr);
//     //     //std::cout << "5\n"; //
//     //     cv::imshow("image", image);
//     //     cv::waitKey(1);
//     // }

//     // cv::destroyAllWindows();

//     remoteUtils->disconnectCamera();
//     //remoteUtils->releaseCamera();
//     //remoteUtils->releaseSDK();
//     cli::tout << "Release SDK resources.\n";
//     SDK::Release();
//     return 0;
// }

// bool outOfRange(std::string mode, uint8_t currentISOIndex, rmUtils::RemoteUtils *remoteUtils)
// {
//     int minInd = remoteUtils->isoMinInd;
//     int maxInd = remoteUtils->isoMaxInd;
//     int keepInd;
//     if (mode == "Underexpose")
//     {
//         keepInd = minInd;
//     }
//     else
//     {
//         keepInd = maxInd;
//     }

//     if ((currentISOIndex <= minInd) || (currentISOIndex >= maxInd))
//     {
//         std::cout << mode << ", new currentISOIndex is out of range, keep current ISO(index:"
//                   << keepInd << std::endl;
//         return true;
//     }
//     return false;
// }

// uint8_t adjustAlg_1(float percentRegion[], uint8_t currentISOIndex, rmUtils::RemoteUtils *remoteUtils)
// {
//     if(sizeof(percentRegion)/sizeof(percentRegion[0] != 3)
//     {
//         std::cout << "Boundaries from user is not suitable to Alg_1." << std::endl;
//         exit(EXIT_FAILURE);
//     }
//     uint8_t margin = 50;
//     uint8_t adjustStep = 2;
//     uint8_t newISOIndex = currentISOIndex;

//     if (percentRegion[0] > percentRegion[1] - margin)
//     {
//         newISOIndex += adjustStep;
//         if (outOfRange("Underexpose", currentISOIndex, remoteUtils))
//         {
//             return currentISOIndex;
//         }
//         std::cout << "Underexpose, New ISO Index: " << std::to_string(newISOIndex) << std::endl;
//         return newISOIndex;
//     }
//     else if (percentRegion[2] > percentRegion[1] - margin)
//     {
//         newISOIndex -= adjustStep;
//         if (outOfRange("Overexpose", currentISOIndex, remoteUtils))
//         {
//             return currentISOIndex;
//         }
//         std::cout << "Overexpose, New ISO Index: " << std::to_string(newISOIndex) << std::endl;
//         return newISOIndex;
//     }
//     else
//     {
//         std::cout << "Normal img." << std::endl;
//     }
//     return currentISOIndex;
// }

// uint8_t adjustAlg_2(float percentRegion[], uint8_t currentISOIndex, rmUtils::RemoteUtils *remoteUtils)
// {
//     if(sizeof(percentRegion)/sizeof(percentRegion[0] != 5)
//     {
//         std::cout << "Boundaries from user is not suitable to Alg_2." << std::endl;
//         exit(EXIT_FAILURE);
//     }
//     uint8_t margin = 50;
//     uint8_t adjustStepL = 3;
//     uint8_t adjustStepS = 2;
//     uint8_t newISOIndex = currentISOIndex;

//     if ((percentRegion[1] > percentRegion[2] - margin) || (percentRegion[0] > percentRegion[2] - margin))
//     {
//         newISOIndex += 1;
//         if (percentRegion[0] > percentRegion[2])
//         {
//             newISOIndex += 1;
//         }
//         if (outOfRange("Overexpose", newISOIndex, remoteUtils))
//         {
//             return currentISOIndex;
//         }
//         std::cout << "Underexpose, New ISO Index: " << std::to_string(newISOIndex) << std::endl;
//         return newISOIndex;
//     }
//     else if ((percentRegion[3] > percentRegion[2] - margin) || (percentRegion[4] > percentRegion[2] - margin))
//     {
//         newISOIndex -= 1;
//         if (percentRegion[4] > percentRegion[2])
//         {
//             newISOIndex -= 1;
//         }
//         if (outOfRange("Overexpose", newISOIndex, remoteUtils))
//         {
//             return currentISOIndex;
//         }
//         std::cout << "Overerexpose, New ISO Index: " << std::to_string(newISOIndex) << std::endl;
//         return newISOIndex;
//     }
//     else
//     {
//         std::cout << "Normal img." << std::endl;
//     }
//     return currentISOIndex;
// }

// void getImgInfo(string name, Mat img)
// {
//     std::cout << name << "size: " << img.size() << ", channels: " << img.channels() << ", depth: " << img.depth() << std::endl;
// }

// void parsArgs(int argc, char *argv[], vector<int> *boundaries)
// {
//     // printf(*writeImg ? "t" : "f");
//     for (uint8_t i = 1; i < argc; i++)
//     {
//         if (static_cast<string>(argv[i]) == "-b")
//         {
//             uint8_t bNumbers = argc - 1 - i;

//             for (uint8_t j = 1; j <= bNumbers; j++)
//             {
//                 boundaries->push_back(atoi(argv[i + j]));
//                 boundaries->push_back(255 - (*boundaries).back());
//             }
//         }
//     }
//     sort(boundaries->begin(), boundaries->end());
//     cout << "Set the boundaries = ";
//     for (int i = 0; i < boundaries->size(); i++)
//     {
//         cout << boundaries->at(i) << " ";
//     }
//     cout << endl;
// }

// std::string parsISO(std::string isoStr)
// {
//     int isoStrL = isoStr.length();
//     std::size_t found = isoStr.rfind("ISO ");
//     if (found != std::string::npos)
//     {
//         std::string subStr = isoStr.substr(found + 1, isoStrL + 1);
//         return subStr;
//     }
//     return "Not found";
// }

// void getUserInput()
// {
//     int stopKey = std::getchar();
//     while (stopKey != '0')
//     {
//         stopKey = std::getchar();
//     }
//     isStop = true;
// }

// std::string getImgName(int imgCount, std::string imgPrefix, int zeroCapacity, std::string savePath, std::string imgExtend)
// {
//     std::string imgName = imgPrefix;
//     char tmp[256];
//     getcwd(tmp, 256);
//     std::string workDir = tmp;

//     int digits = countDigits(imgCount);
//     for (int i = 0; i <= zeroCapacity - digits; i++)
//     {
//         imgName = imgName + "0";
//     }
//     imgName = imgName + std::to_string(imgCount);

//     return workDir + "/" + savePath + imgName + imgExtend;
// }

// template <typename T>
// size_t countDigits(T n)
// {
//     string tmp;

//     tmp = std::to_string(n);
//     return tmp.size();
// }

// void resetPR(float percentRegion[])
// {
//     for (int i = 0; i < sizeof(percentRegion) / sizeof(percentRegion[0]); i++)
//     {
//         percentRegion[i] = 0;
//     }
// }

// std::string calFPS(double startTC, double endTC) // use template to return
// {
//     double spendT = 0.0;
//     double startT = startTC;
//     double endT = endTC;
//     std::string fpsStr;

//     spendT = (endT - startT) / cv::getTickFrequency() * 1000;
//     fpsStr = "FPS: " + std::to_string(int(1000.0f / spendT * 100) / 100.f);
//     return fpsStr;
// }

// bool drawText(cv::Mat image, std::string textStr)
// {
//     if (!image.data)
//     {
//         printf("No image data \n");
//         return false;
//     }

//     cv::Mat textPane(35, 155, CV_8UC3);
//     textPane.setTo(cv::Scalar(153, 119, 76));
//     cv::Mat srcRegion = image(cv::Rect(8, 8, textPane.cols, textPane.rows));
//     cv::addWeighted(srcRegion, 0.4, textPane, 0.6, 0, srcRegion);
//     cv::putText(image, textStr, cv::Point(16, 32),
//                 cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(0, 0, 255));
//     return true;
// }

// std::string getCurrentT()
// {
//     char tt[100];
//     time_t now = time(nullptr);
//     auto tm_info = localtime(&now);
//     strftime(tt, 100, "%Y-%m-%d_%H:%M:%S", tm_info);
//     return std::string(tt);
// }

// #include <memory>
// #include <stdlib.h>
// #include <iostream>
// #include <thread>
// #include <stdio.h>
// #include <sstream>
// #include <string>
// #include <unistd.h>
// #include <opencv2/opencv.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/imgproc.hpp>
// #include <experimental/filesystem>
// namespace fs = std::experimental::filesystem;
// #include "CRSDK/CameraRemote_SDK.h"
// namespace SDK = SCRSDK;
// #include "RemoteUtils.h"
// #include "histUtils.h"

// bool isStop = false;
// void getUserInput();

// std::string calFPS(int64_t, int64_t);
// void getLiveView();
// bool drawText(cv::Mat, std::string);
// void getPercentage(int countRegion[]);
// std::string getCurrentT();

// void adjustISO(int argc, char *argv[], rmUtils::RemoteUtils *remoteUtils, std::string savePath);
// void getImgInfo(std::string name, cv::Mat img);
// void parsArgs(int argc, char *argv[], vector<int> *boundaries);
// std::string parsISO(std::string isoStr);
// std::string getImgName(int imgCount, std::string imgPrefix, int zeroCapacity, std::string savePath, std::string imgExtend);
// template <typename T>
// size_t countDigits(T n);
// void resetPR(float percentRegion[]);
// /*
// ./RemoteCli -b 10
// */
// int main(int argc, char *argv[])
// {
//     std::string savePath = "";
//     rmUtils::RemoteUtils *remoteUtils = new rmUtils::RemoteUtils();
//     remoteUtils->initRemoteSDK();
//     remoteUtils->initCamera();
//     savePath = remoteUtils->setSaveInfo("image/" + getCurrentT(), true) + "/";
//     if (savePath == "Failed to set save path.")
//     {
//         remoteUtils->release();
//         return -1;
//     }
//     std::this_thread::sleep_for(std::chrono::milliseconds(3000));

//     adjustISO(argc, argv, remoteUtils, savePath);

//     // getLiveView();

//     remoteUtils->disconnectCamera();
//     //remoteUtils->releaseCamera();
//     //remoteUtils->releaseSDK();
//     cli::tout << "Release SDK resources.\n";
//     SDK::Release();
//     return 0;
// }

// void adjustISO(int argc, char *argv[], rmUtils::RemoteUtils *remoteUtils, std::string savePath)
// {
//     cv::Mat img;
//     cv::Mat lightness;
//     std::vector<int> boundaries;
//     std::string imgPrefix = "DSC";
//     std::string imgExtend = ".JPG";
//     int zeroCapacity = 4;
//     uint32_t imgCount = 0;
//     uint8_t adjustStep = 2;
//     int adjustWT = 800;
//     int captureWT = 2000;
//     uint8_t margin = 50;

//     std::string originISO = remoteUtils->getISO();
//     if (remoteUtils->isoOpts.find(originISO) == remoteUtils->isoOpts.end())
//     {
//         printf("originISO not in remoteUtils->isoOpts, set 3,200 \n");
//         remoteUtils->setISO(remoteUtils->isoOpts["3,200"]);
//         originISO = "3,200";
//         std::this_thread::sleep_for(std::chrono::milliseconds(adjustWT));
//     }
//     uint8_t originISOIndex = remoteUtils->isoOpts[originISO];
//     uint8_t currentISOIndex = originISOIndex;
//     std::cout << "Original ISO: " << originISO << ", Index: " << std::to_string(originISOIndex) << std::endl;

//     parsArgs(argc, argv, &boundaries);
//     int regionNum = boundaries.size() + 1;
//     float percentRegion[regionNum] = {0};

//     std::thread userInputThread(getUserInput);
//     userInputThread.detach();
//     for (;;)
//     {
//         if (isStop)
//         {
//             std::cout << "User input to stop loop.\n";
//             break;
//         }
//         std::cout << "============================================" << std::endl;
//         imgCount += 1;
//         resetPR(percentRegion);
//         std::string imgName = getImgName(imgCount, imgPrefix, zeroCapacity, savePath, imgExtend);
//         remoteUtils->capture_Image(); ///////////////////////////////////////////////////
//         std::this_thread::sleep_for(std::chrono::milliseconds(captureWT));

//         img = cv::imread(imgName);
//         if (!img.data)
//         {
//             printf("No image data \n");
//             continue;
//         }
//         getLightness(img, &lightness);
//         calPercentage(imgName, lightness, boundaries, percentRegion, true);

//         if (percentRegion[0] > percentRegion[1] - margin)
//         {
//             if ((currentISOIndex <= remoteUtils->isoMinInd) || (currentISOIndex >= remoteUtils->isoMaxInd))
//             {
//                 std::cout << "Underexpose, new currentISOIndex is out of range, keep current ISO(index:" << remoteUtils->isoMinInd << std::endl;
//                 continue;
//             }
//             currentISOIndex += adjustStep;
//             imgCount += 1;
//             std::string imgName = getImgName(imgCount, imgPrefix, zeroCapacity, savePath, imgExtend);

//             resetPR(percentRegion);
//             remoteUtils->setISO(currentISOIndex);
//             std::this_thread::sleep_for(std::chrono::milliseconds(adjustWT));
//             std::cout << "Underexpose, New ISO Index: " << std::to_string(currentISOIndex) << ", value: " << remoteUtils->getISO() << std::endl;
//             remoteUtils->capture_Image(); ///////////////////////////////////////////////////
//             std::this_thread::sleep_for(std::chrono::milliseconds(captureWT));
//             img = cv::imread(imgName);
//             getLightness(img, &lightness);
//             calPercentage(imgName, lightness, boundaries, percentRegion, true);
//         }
//         else if (percentRegion[2] > percentRegion[1] - margin)
//         {
//             if ((currentISOIndex <= remoteUtils->isoMinInd) || (currentISOIndex >= remoteUtils->isoMaxInd))
//             {
//                 std::cout << "Overexpose, currentISOIndex == max value in isoOpts, keep current ISO(index:" << remoteUtils->isoMaxInd << std::endl;
//                 continue;
//             }
//             currentISOIndex -= adjustStep;
//             imgCount += 1;
//             std::string imgName = getImgName(imgCount, imgPrefix, zeroCapacity, savePath, imgExtend);

//             resetPR(percentRegion);
//             remoteUtils->setISO(currentISOIndex);
//             std::this_thread::sleep_for(std::chrono::milliseconds(adjustWT));
//             std::cout << "Overexpose, New ISO Index: " << std::to_string(currentISOIndex) << ", value: " << remoteUtils->getISO() << std::endl;
//             remoteUtils->capture_Image(); ///////////////////////////////////////////////////
//             std::this_thread::sleep_for(std::chrono::milliseconds(captureWT));
//             img = cv::imread(imgName);
//             getLightness(img, &lightness);
//             calPercentage(imgName, lightness, boundaries, percentRegion, true);
//         }
//         else
//         {
//             std::cout << "Normal img." << std::endl;
//         }
//     }
// }

// void getLiveView()
// {
//     // //LiveView
//     // double startTC, endTC;
//     // char stopChar;
//     // std::string fpsStr;
//     // cv::Mat image;
//     // std::string liveViewName = "LiveView000000.JPG";
//     // cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
//     // std::cout << "New a LiveView Window.\n";

//     // std::thread userInputThread(getUserInput);
//     // std::cout << "Start loop(press '0' to quit)\n";
//     // for (;;)
//     // {
//     // if(isStop){
//     //     std::cout << "User input to stop loop.\n";
//     //     break;
//     // }
//     //     //std::cout << "1\n";
//     //     double inferenceTime = 0.0;
//     //     double t1 = static_cast<double>(cv::getTickCount()); //startTC = (double)cv::getTickFrequency(); //get start tick count
//     //     //std::cout << "2\n";
//     //     remoteUtils->getLiveView();
//     // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     //     double t2 = static_cast<double>(cv::getTickCount()); //endTC = (double)cv::getTickFrequency(); //get end tick count
//     //     inferenceTime = (t2 - t1) / cv::getTickFrequency() * 1000;
//     //     std::string fpsStr;
//     //     fpsStr = "FPS: " +std::to_string(int(1000.0f / inferenceTime * 100) / 100.0f); //fpsStr = calFPS(startTC, endTC);
//     //     //std::cout << "3\n";
//     //     image = cv::imread(liveViewName, 1);
//     //     //std::cout << "4\n"; //
//     // std::cout << fpsStr << "\n";//drawText(image, fpsStr);
//     //     //std::cout << "5\n"; //
//     //     cv::imshow("image", image);
//     //     cv::waitKey(1);
//     // }

//     // cv::destroyAllWindows();
// }

// void getImgInfo(string name, Mat img)
// {
//     std::cout << name << "size: " << img.size() << ", channels: " << img.channels() << ", depth: " << img.depth() << std::endl;
// }

// void parsArgs(int argc, char *argv[], vector<int> *boundaries)
// {
//     // printf(*writeImg ? "t" : "f");
//     for (uint8_t i = 1; i < argc; i++)
//     {
//         if (static_cast<string>(argv[i]) == "-b")
//         {
//             uint8_t bNumbers = argc - 1 - i;

//             for (uint8_t j = 1; j <= bNumbers; j++)
//             {
//                 boundaries->push_back(atoi(argv[i + j]));
//                 boundaries->push_back(255 - (*boundaries).back());
//             }
//         }
//     }
//     sort(boundaries->begin(), boundaries->end());
//     cout << "Set the boundaries = ";
//     for (int i = 0; i < boundaries->size(); i++)
//     {
//         cout << boundaries->at(i) << " ";
//     }
//     cout << endl;
// }

// std::string parsISO(std::string isoStr)
// {
//     int isoStrL = isoStr.length();
//     std::size_t found = isoStr.rfind("ISO ");
//     if (found != std::string::npos)
//     {
//         std::string subStr = isoStr.substr(found + 1, isoStrL + 1);
//         return subStr;
//     }
//     return "Not found";
// }

// void getUserInput()
// {
//     int stopKey = std::getchar();
//     while (stopKey != '0')
//     {
//         stopKey = std::getchar();
//     }
//     isStop = true;
// }

// std::string getImgName(int imgCount, std::string imgPrefix, int zeroCapacity, std::string savePath, std::string imgExtend)
// {
//     std::string imgName = imgPrefix;
//     char tmp[256];
//     getcwd(tmp, 256);
//     std::string workDir = tmp;

//     int digits = countDigits(imgCount);
//     for (int i = 0; i <= zeroCapacity - digits; i++)
//     {
//         imgName = imgName + "0";
//     }
//     imgName = imgName + std::to_string(imgCount);

//     return workDir + "/" + savePath + imgName + imgExtend;
// }

// template <typename T>
// size_t countDigits(T n)
// {
//     string tmp;

//     tmp = std::to_string(n);
//     return tmp.size();
// }

// void resetPR(float percentRegion[])
// {
//     for (int i = 0; i < sizeof(percentRegion) / sizeof(percentRegion[0]); i++)
//     {
//         percentRegion[i] = 0;
//     }
// }

// std::string calFPS(double startTC, double endTC) // use template to return
// {
//     double spendT = 0.0;
//     double startT = startTC;
//     double endT = endTC;
//     std::string fpsStr;

//     spendT = (endT - startT) / cv::getTickFrequency() * 1000;
//     fpsStr = "FPS: " + std::to_string(int(1000.0f / spendT * 100) / 100.f);
//     return fpsStr;
// }

// bool drawText(cv::Mat image, std::string textStr)
// {
//     if (!image.data)
//     {
//         printf("No image data \n");
//         return false;
//     }

//     cv::Mat textPane(35, 155, CV_8UC3);
//     textPane.setTo(cv::Scalar(153, 119, 76));
//     cv::Mat srcRegion = image(cv::Rect(8, 8, textPane.cols, textPane.rows));
//     cv::addWeighted(srcRegion, 0.4, textPane, 0.6, 0, srcRegion);
//     cv::putText(image, textStr, cv::Point(16, 32),
//                 cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(0, 0, 255));
//     return true;
// }

// std::string getCurrentT()
// {
//     char tt[100];
//     time_t now = time(nullptr);
//     auto tm_info = localtime(&now);
//     strftime(tt, 100, "%Y-%m-%d_%H:%M:%S", tm_info);
//     return std::string(tt);
// }
// // #include <cstdlib>
// // //#if defined(USE_EXPERIMENTAL_FS)
// // #include <experimental/filesystem>
// // namespace fs = std::experimental::filesystem;
// // //#else
// // //#include <filesystem>
// // // namespace fs = std::filesystem;
// // #if defined(__APPLE__)
// // #include <unistd.h>
// // #endif
// // //#endif
// // #include "CRSDK/CameraRemote_SDK.h"
// // #include "RemoteUtils.h"
// // #include "Text.h"
// // #include "CameraDevice.h"
// // #include <chrono>
// // #include <cstdint>
// // #include <iomanip>
// // #include <thread>
// // #include <string>
// // #include <opencv2/opencv.hpp>

// // //#define LIVEVIEW_ENB

// // namespace SDK = SCRSDK;

// // // Global dll object
// // // cli::CRLibInterface* cr_lib = nullptr;
// // int main()
// // {
// //     // Change global locale to native locale
// //     std::locale::global(std::locale(""));

// //     // Make the stream's locale the same as the current global locale
// //     cli::tin.imbue(std::locale());
// //     cli::tout.imbue(std::locale());

// //     cli::tout << "RemoteSampleApp v1.04.00 running...\n\n";

// //     CrInt32u version = SDK::GetSDKVersion();
// //     int major = (version & 0xFF000000) >> 24;
// //     int minor = (version & 0x00FF0000) >> 16;
// //     int patch = (version & 0x0000FF00) >> 8;
// //     // int reserved = (version & 0x000000FF);

// //     cli::tout << "Remote SDK version: ";
// //     cli::tout << major << "." << minor << "." << std::setfill(TEXT('0')) << std::setw(2) << patch << "\n";

// //     // Load the library dynamically
// //     // cr_lib = cli::load_cr_lib();

// //     cli::tout << "Initialize Remote SDK...\n";

// // #if defined(__APPLE__)
// //     char path[255]; /*MAX_PATH*/
// //     getcwd(path, sizeof(path) - 1);
// //     cli::tout << "Working directory: " << path << '\n';
// // #else
// //     cli::tout << "Working directory: " << fs::current_path() << '\n';
// // #endif
// //     // auto init_success = cr_lib->Init(0);
// //     auto init_success = SDK::Init();
// //     if (!init_success)
// //     {
// //         cli::tout << "Failed to initialize Remote SDK. Terminating.\n";
// //         // cr_lib->Release();
// //         SDK::Release();
// //         std::exit(EXIT_FAILURE);
// //     }
// //     cli::tout << "Remote SDK successfully initialized.\n\n";

// //     cli::tout << "Enumerate connected camera devices...\n";
// //     SDK::ICrEnumCameraObjectInfo *camera_list = nullptr;
// //     // auto enum_status = cr_lib->EnumCameraObjects(&camera_list, 3);
// //     auto enum_status = SDK::EnumCameraObjects(&camera_list);
// //     if (CR_FAILED(enum_status) || camera_list == nullptr)
// //     {
// //         cli::tout << "No cameras detected. Connect a camera and retry.\n";
// //         // cr_lib->Release();
// //         SDK::Release();
// //         std::exit(EXIT_FAILURE);
// //     }
// //     auto ncams = camera_list->GetCount();
// //     cli::tout << "Camera enumeration successful. " << ncams << " detected.\n\n";

// //     for (CrInt32u i = 0; i < ncams; ++i)
// //     {
// //         auto camera_info = camera_list->GetCameraObjectInfo(i);
// //         cli::text conn_type(camera_info->GetConnectionTypeName());
// //         cli::text model(camera_info->GetModel());
// //         cli::text id = TEXT("");
// //         if (TEXT("IP") == conn_type)
// //         {
// //             cli::NetworkInfo ni = cli::parse_ip_info(camera_info->GetId(), camera_info->GetIdSize());
// //             id = ni.mac_address;
// //         }
// //         else
// //             id = ((TCHAR *)camera_info->GetId());
// //         cli::tout << '[' << i + 1 << "] " << model.data() << " (" << id.data() << ")\n";
// //     }

// //     cli::tout << std::endl
// //               << "Connect to camera with input number...\n";
// //     cli::tout << "input> ";
// //     cli::text connectNo;
// //     std::getline(cli::tin, connectNo);
// //     cli::tout << '\n';

// //     cli::tsmatch smatch;
// //     CrInt32u no = 0;
// //     while (true)
// //     {
// //         no = 0;
// //         if (std::regex_search(connectNo, smatch, cli::tregex(TEXT("[0-9]"))))
// //         {
// //             no = stoi(connectNo);
// //             if (no == 0)
// //                 break; // finish

// //             if (camera_list->GetCount() < no)
// //             {
// //                 cli::tout << "input value over \n";
// //                 cli::tout << "input> "; // Redo
// //                 std::getline(cli::tin, connectNo);
// //                 continue;
// //             }
// //             else
// //                 break; // ok
// //         }
// //         else
// //             break; // not number
// //     }

// //     if (no == 0)
// //     {
// //         cli::tout << "Invalid Number. Finish App.\n";
// //         SDK::Release();
// //         std::exit(EXIT_FAILURE);
// //     }

// //     typedef std::shared_ptr<cli::CameraDevice> CameraDevicePtr;
// //     typedef std::vector<CameraDevicePtr> CameraDeviceList;
// //     CameraDeviceList cameraList; // all
// //     std::int32_t cameraNumUniq = 1;
// //     std::int32_t selectCamera = 1;

// //     cli::tout << "Connect to selected camera...\n";
// //     auto *camera_info = camera_list->GetCameraObjectInfo(no - 1);

// //     cli::tout << "Create camera SDK camera callback object.\n";
// //     CameraDevicePtr camera = CameraDevicePtr(new cli::CameraDevice(cameraNumUniq, nullptr, camera_info));
// //     cameraList.push_back(camera); // add 1st

// //     cli::tout << "Release enumerated camera list.\n";
// //     camera_list->Release();

// //     auto connect_status = camera->connect();
// //     if (!connect_status)
// //     {
// //         cli::tout << "Camera connection failed to initiate. Abort.\n";
// //         // cr_lib->Release();
// //         SDK::Release();
// //         std::exit(EXIT_FAILURE);
// //     }
// //     cli::tout << "Camera connection successfully initiated!\n\n";

// //     std::this_thread::sleep_for(std::chrono::milliseconds(3000));
// //     ////////////////////////////////////////////////////////////////////////////////////
// //     // Utils
// //     ////////////////////////////////////////////////////////////////////////////////////
// //     //camera->capture_image();
// //     std::this_thread::sleep_for(std::chrono::milliseconds(3000));

// //     // cli::tout << "capture_image function is call.\n";
// //     // cli::tout << "Capture image...\n";
// //     // cli::tout << "Shutter down\n";
// //     // SDK::SendCommand(camera->m_device_handle,
// //     //                  SDK::CrCommandId::CrCommandId_Release,
// //     //                  SDK::CrCommandParam_Down);
// //     // // Wait, then send shutter up
// //     // // std::this_thread::sleep_for(35ms);
// //     // std::this_thread::sleep_for(std::chrono::milliseconds(35));
// //     // cli::tout << "Shutter up\n";
// //     // SDK::SendCommand(camera->m_device_handle,
// //     //                  SDK::CrCommandId::CrCommandId_Release,
// //     //                  SDK::CrCommandParam_Up);
// //     // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

// //     // cli::tout << "S1 shooting...\n";
// //     // cli::tout << "Shutter Halfpress down\n";
// //     // SDK::CrDeviceProperty prop;
// //     // prop.SetCode(SDK::CrDevicePropertyCode::CrDeviceProperty_S1);
// //     // prop.SetCurrentValue(SDK::CrLockIndicator::CrLockIndicator_Locked);
// //     // prop.SetValueType(SDK::CrDataType::CrDataType_UInt16);
// //     // SDK::SetDeviceProperty(camera->m_device_handle, &prop);

// //     // // Wait, then send shutter down
// //     // std::this_thread::sleep_for(std::chrono::milliseconds(500));
// //     // cli::tout << "Shutter down\n";
// //     // SDK::SendCommand(camera->m_device_handle, SDK::CrCommandId::CrCommandId_Release, SDK::CrCommandParam::CrCommandParam_Down);

// //     // // Wait, then send shutter up
// //     // std::this_thread::sleep_for(std::chrono::milliseconds(35));
// //     // cli::tout << "Shutter up\n";
// //     // SDK::SendCommand(camera->m_device_handle, SDK::CrCommandId::CrCommandId_Release, SDK::CrCommandParam::CrCommandParam_Up);

// //     // // Wait, then send shutter up
// //     // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
// //     // cli::tout << "Shutter Halfpress up\n";
// //     // prop.SetCurrentValue(SDK::CrLockIndicator::CrLockIndicator_Unlocked);
// //     // SDK::SetDeviceProperty(camera->m_device_handle, &prop);
// //     ////////////////////////////////////////////////////////////////////////////////////
// //     // Release
// //     ////////////////////////////////////////////////////////////////////////////////////
// //     cli::tout << "Release SDK resources.\n";
// //     // cr_lib->Release();
// //     SDK::Release();

// //     // cli::free_cr_lib(&cr_lib);
// //     cli::tout << "Release camera...\n";
// //     // auto finalize_status = m_cr_lib->FinalizeDevice(m_device_handle);
// //     auto finalize_status = SDK::ReleaseDevice(camera->m_device_handle);
// //     camera->m_device_handle = 0; // clear
// //     if (CR_FAILED(finalize_status))
// //     {
// //         cli::tout << "Finalize device failed to initialize.\n";
// //     }

// //     cli::tout << "Exiting application.\n";
// //     std::exit(EXIT_SUCCESS);
// // }