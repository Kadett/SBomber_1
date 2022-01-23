#include "MyTools.h"

#include <cstdint>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>



namespace MyTools {

    std::ofstream logOut;

    void FileLoggerSingletone::OpenLogFile(const std::string &FN) {
        logOut.open(FN, std::ios_base::out);
    }

    void FileLoggerSingletone::CloseLogFile() {
        if (logOut.is_open()) {
            logOut.close();
        }
    }

    std::string FileLoggerSingletone::GetCurDateTime() {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char *buf = ctime(&time);
        return std::string(buf);
    }

    void FileLoggerSingletone::WriteToLog(const std::string &str) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << str << std::endl;
        }

    }

    void FileLoggerSingletone::WriteToLog(const std::string &str, int n) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << str << n << std::endl;
        }
    }

    void FileLoggerSingletone::WriteToLog(const std::string &str, double d) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << str << d << std::endl;
        }
    }




    int LoggerSingleton::lineNumber{0};
    void LoggerSingleton::OpenLogFile(const std::string &FN) {
        FileLoggerSingletone::getInstance().OpenLogFile(FN);
    }

    void LoggerSingleton::CloseLogFile() {
        FileLoggerSingletone::getInstance().CloseLogFile();
    }

    void LoggerSingleton::WriteToLog(const std::string &str) {
        writeLineNumber();
        FileLoggerSingletone::getInstance().WriteToLog(str);
    }

    void LoggerSingleton::WriteToLog(const std::string &str, int n) {
        writeLineNumber();
        FileLoggerSingletone::getInstance().WriteToLog(str, n);
    }

    void LoggerSingleton::WriteToLog(const std::string &str, double d) {
        writeLineNumber();
        FileLoggerSingletone::getInstance().WriteToLog(str, d);
    }

    void LoggerSingleton::writeLineNumber() {
        if (logOut.is_open()) {
            logOut << LoggerSingleton::lineNumber << "   ";
            LoggerSingleton::lineNumber++;
        }
    }

} // namespace MyTools
