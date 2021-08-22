#include <string.h>
#include <ostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#include <fstream>

namespace logUtils
{
    class LogUtils
    {
    public:
        LogUtils();
        LogUtils(std::string path);

        bool writeInfo(std::string info);

    public:
        std::string logFileName;
        std::string logFilePath;
    };
}