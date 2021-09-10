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

using namespace cv;
using namespace std;

void sum(int x, int y, int *z)
{
    *z = x + y;
}

bool isStop = false;
void getUserInput()
{
  int stopKey = std::getchar();
  while (stopKey != 'q')
  {
    stopKey = std::getchar();
  }
  isStop = true;
}

void myfunc()
{
    int i = 0;

    for (int i=0; i<10; i++)
    {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    // do something ...
}

int main()
{
    std::thread t1(myfunc);
    // t1.detach();

    std::cout << "main" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "finish sleep" << std::endl;
    isStop = true;

    t1.join();
    return 0;
}