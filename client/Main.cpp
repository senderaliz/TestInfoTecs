#include "Lib.h"

int main()
{
    auto *logger = Lib::CreateLogger();
    bool check = logger->Init("/mnt/e/InfoTecs/log.txt", Lib::Logger::Level::STANDART);

    logger->Log("1", Lib::Logger::Level::STANDART);
    logger->Log("2", Lib::Logger::Level::NON_IMPORTANT);
    logger->Log("5", Lib::Logger::Level::IMPORTANT);
    return 0;
}