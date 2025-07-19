#include "Lib.h"

int main()
{
    auto *logger = Lib::CreateLogger();
    bool check = logger->Init("/mnt/e/InfoTecs/log.txt", Lib::Logger::Level::LOW);

    logger->Log("Message 1", Lib::Logger::Level::STANDART);
    logger->Log("Message 2", Lib::Logger::Level::LOW);
    logger->Log("Message 3", Lib::Logger::Level::HIGH);
    return 0;
}