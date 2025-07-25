#pragma once
#include <iostream>

namespace Lib
{
    class LoggerInterface
    {
    public:
        enum class Level
        {
            LOW = 1,
            STANDART = 2,
            HIGH = 3
        };

    public:
        virtual ~LoggerInterface() = default;
        virtual void Log(const char* message, Level level) = 0;
        virtual void SetDefaultLevel(Level level) = 0;
    };

    LoggerInterface* CreateLoggerFile(const char *filePath, LoggerInterface::Level defaultLevel);
    void DeleteLoggerFile(LoggerInterface* ptr);
    
    LoggerInterface* CreateLoggerSocket(int socket, LoggerInterface::Level defaultLevel);
    void DeleteLoggerSocket(LoggerInterface* ptr);

}