#################################################
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
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <chrono>
#include <ctime>
#include <sys/stat.h>
#include <torch/torch.h>
namespace fs = std::experimental::filesystem;

using namespace cv;
using namespace std;
/*

*/

int main() {
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}
