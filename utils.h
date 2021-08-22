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
namespace fs = std::experimental::filesystem;

using namespace cv;
using namespace std;

void parsArgs(int argc, char* argv[], bool* writeImg, vector<int>* boundaries);
string getImgName(string fullName);
void getImgInfo(string name, Mat img);
void updateCount(int val, int count_, int countRegion[], vector<int> boundaries);
void calPercentage(string name, Mat lightHist, Mat img, int countRegion[], int regionNum, vector<int> boundaries, int histSize);
void showHist(string name, Mat img, vector<int> boundaries, bool writeImg = false);