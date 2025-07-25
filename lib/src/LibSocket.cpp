#include "Lib.h"

#include <cstring>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class LoggerSocket : public Lib::LoggerInterface
{
public:
    bool Init(int socket, Level level);
    void Log(const char *message, Level level) override;
    void SetDefaultLevel(Level level) override;

private:
    const char *LevelStr(Level l);

    int _sock = -1;
    Level _defaultLevel = Level::STANDART;
};

bool LoggerSocket::Init(int socket, Lib::LoggerInterface::Level defaultLevel)
{
    if (socket < 0)
    {
        return false;
    }
    _defaultLevel = defaultLevel;
    _sock = socket;
    return true;
}
void LoggerSocket::Log(const char *message, Level level)
{
    if (level >= _defaultLevel)
    {
        auto t = std::time(nullptr);
        auto localTime = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << " | ";

        switch (level)
        {
        case Lib::LoggerInterface::Level::LOW:
            oss << "low | ";
            break;
        case Lib::LoggerInterface::Level::STANDART:
            oss << "standart | ";
            break;
        case Lib::LoggerInterface::Level::HIGH:
            oss << "high | ";
            break;
        }
        oss << message << std::endl;

        send(_sock, oss.str().c_str(), oss.str().length(), MSG_DONTWAIT);
    }
}

void LoggerSocket::SetDefaultLevel(Level level)
{
    _defaultLevel = level;
}

Lib::LoggerInterface *Lib::CreateLoggerSocket(int socket, LoggerInterface::Level defaultLevel)
{
    auto *ptr = new LoggerSocket;
    if (!ptr->Init(socket, defaultLevel))
    {
        delete ptr;
        return nullptr;
    }
    return ptr;
}

void Lib::DeleteLoggerSocket(LoggerInterface *ptr)
{
    delete ptr;
}
