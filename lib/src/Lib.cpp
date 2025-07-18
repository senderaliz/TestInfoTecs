#include "Lib.h"

#include <fstream>

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
        _fout << message << std::endl;
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