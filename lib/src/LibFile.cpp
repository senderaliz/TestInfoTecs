#include "Lib.h"

#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

class LoggerFile : public Lib::LoggerInterface
{
public:
    bool Init(const char *filePath, Level defaultLevel);
    void Log(const char *message, Level level) override;
    void SetDefaultLevel(Level level) override;

private:
    Level _defaultLevel = Level::STANDART;
    std::ofstream _fout;
};

bool LoggerFile::Init(const char *filePath, Level defaultLevel)
{
    _defaultLevel = defaultLevel;
    _fout.open(filePath);
    if (!_fout.is_open())
    {
        return false;
    }
    return true;
}

void LoggerFile::Log(const char *message, Level level)
{
    if (level >= _defaultLevel)
    {
        auto t = std::time(nullptr);

        auto localTime = *std::localtime(&t);
        _fout << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << " | ";

        switch (level)
        {
        case Lib::LoggerInterface::Level::LOW:
            _fout << "low | ";
            break;
        case Lib::LoggerInterface::Level::STANDART:
            _fout << "standart | ";
            break;
        case Lib::LoggerInterface::Level::HIGH:
            _fout << "high | ";
            break;
        }
        _fout << message << std::endl;
    }
}

void LoggerFile::SetDefaultLevel(Level level)
{
    _defaultLevel = level;
}

Lib::LoggerInterface *Lib::CreateLoggerFile(const char *filePath, LoggerInterface::Level defaultLevel)
{
    auto *ptr = new LoggerFile;
    if (!ptr->Init(filePath, defaultLevel))
    {
        delete ptr;
        return nullptr;
    }
    return ptr;
}

void Lib::DeleteLoggerFile(LoggerInterface *ptr)
{
    delete ptr;
}
