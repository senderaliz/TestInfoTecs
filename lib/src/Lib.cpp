#include "Lib.h"

#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

class LoggerImpl : public Lib::Logger
{
public:
    bool Init(const char *filePath, Level defaultLevel) override;
    void Log(const char *message, Level level) override;

private:
    Level _defaultLevel = Level::STANDART;
    std::ofstream _fout;
};

bool LoggerImpl::Init(const char *filePath, Level defaultLevel)
{
    _defaultLevel = defaultLevel;
    _fout.open(filePath);
    if (!_fout.is_open())
    {
        return false;
    }
    return true;
}

void LoggerImpl::Log(const char *message, Level level)
{

    if (level >= _defaultLevel)
    {
        auto t = std::time(nullptr);
        auto localTime = *std::localtime(&t);
        _fout << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << " | ";

        switch (level)
        {
        case Lib::Logger::Level::LOW:
            _fout << ", low, ";
            break;
        case Lib::Logger::Level::STANDART:
            _fout << ", standart";
            break;
        case Lib::Logger::Level::HIGH:
            _fout << ", high";
            break;

                    _fout << message << std::endl;
        }
    }
}

Lib::Logger *Lib::CreateLogger()
{
    Logger *ptr = new LoggerImpl;
    return ptr;
}

void Lib::DeleteLogger(Logger *ptr)
{
    LoggerImpl *truePtr = (LoggerImpl *)ptr;
    delete truePtr;
}