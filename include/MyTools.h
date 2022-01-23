#pragma once

#include <string>

namespace MyTools {

    class IFileLogger {
    public:
        virtual void OpenLogFile(const std::string &FN) = 0;

        virtual void CloseLogFile() = 0;

        virtual void WriteToLog(const std::string &str) = 0;

        virtual void WriteToLog(const std::string &str, int n) = 0;

        virtual void WriteToLog(const std::string &str, double d) = 0;
    };

    class FileLoggerSingletone : IFileLogger {
    public:
        static FileLoggerSingletone &getInstance() {
            static FileLoggerSingletone theInstance;
            return theInstance;
        }

        void OpenLogFile(const std::string &FN) override;

        void CloseLogFile() override;

        void WriteToLog(const std::string &str) override;

        void WriteToLog(const std::string &str, int n) override;

        void WriteToLog(const std::string &str, double d) override;

        FileLoggerSingletone() = default;

        FileLoggerSingletone(const FileLoggerSingletone &e) = delete;

        FileLoggerSingletone &operator=(const FileLoggerSingletone &) = delete;

    private:

        std::string GetCurDateTime();
    };

    class LoggerSingleton : IFileLogger {
    public:
        static LoggerSingleton &getInstance() {
            static LoggerSingleton theInstance;
            return theInstance;
        }

        void OpenLogFile(const std::string &FN) override;

        void CloseLogFile() override;

        void WriteToLog(const std::string &str) override;

        void WriteToLog(const std::string &str, int n) override;

        void WriteToLog(const std::string &str, double d) override;

        LoggerSingleton() = default;

        LoggerSingleton(const LoggerSingleton &e) = delete;

        LoggerSingleton &operator=(const LoggerSingleton &) = delete;

        static int lineNumber;
    private:
        void writeLineNumber();
    };

}; // namespace MyTools
