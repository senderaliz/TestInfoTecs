#pragma once

namespace Lib
{
    class Logger
    {
    public:
        enum class Level
        {
            LOW = 0,
            STANDART = 1,
            HIGH = 2
        };

    public:
        virtual bool Init(const char* filePath, Level defaultLevel) = 0;
        virtual void Log(const char* message, Level level) = 0;
    };

    Logger* CreateLogger();
    void DeleteLogger(Logger* ptr);
}