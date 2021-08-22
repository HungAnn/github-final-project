#include "LogUtils.h"
#include <string.h>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#include <fstream>
#include <ostream>
#include <stdio.h>

namespace logUtils
{
    LogUtils::LogUtils(std::string path)
    {
        int pathL = path.length();
        std::size_t found = path.rfind("/");
        if (found != std::string::npos)
        {
            logFileName = path.substr(found + 1, pathL + 1);
        }
        else
        {
            std::cout << "Log file error about directory." << std::endl;
        }

        logFilePath = path + "/" + logFileName + ".txt";
        std::cout << logFilePath << std::endl;
        std::ofstream logFile(logFilePath);
        if (logFile.is_open())
        {
            logFile << "Save path: " << path << "\n";
            logFile.close();
        }
        else
        {
            std::cout << "Log file is not opened." << std::endl;
        }
    };

    bool LogUtils::writeInfo(std::string info)
    {
        std::ofstream logFile;
        logFile.open(logFilePath, std::ios_base::app);

        if (logFile.is_open())
        {
            logFile << info << "\n";
            logFile.close();
        }
        else
        {
            std::cout << "Log file is not opened." << std::endl;
            return false;
        }
        return true;
    }
}
