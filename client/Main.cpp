#include "Lib.h"

std::pair<bool, Lib::LoggerInterface::Level> GetLogLevel(int levelInt)
{
    auto level = Lib::LoggerInterface::Level(levelInt);
    if (level < Lib::LoggerInterface::Level::LOW || level > Lib::LoggerInterface::Level::HIGH)
    {
        return std::pair(false, level);
    }
    return std::pair(true, level);
}

int main()
{
    bool wasInit = false;
    bool execution = true;
    int levelInt = 1;
    std::string logFilePath;
    Lib::LoggerInterface *logger = nullptr;

    std::cout << "Specify the location of the file: ";
    std::cin >> logFilePath;

    std::cout << "Initialization, specify the message importance threshold" << std::endl;
    std::cout << "\n[1] - low," << "\n[2] - standart" << "\n[3] - high" << std::endl;

    std::cin >> levelInt;

    auto levelDefault = GetLogLevel(levelInt);
    if (!levelDefault.first)
    {
        std::cout << "Incorrect importance level value " << std::endl;
        return 1;
    }

    logger = Lib::CreateLoggerFile(logFilePath.c_str(), levelDefault.second);
    if (logger == nullptr)
    {
        std::cout << "Incorrect importance level value" << std::endl;
        return 1;
    }

    while (execution)
    {
        std::string message;
        int operationChoice = 0;

        std::cout << "Select operation: " << std::endl;
        std::cout << "[1] - Change the message importance threshold" << std::endl;
        std::cout << "[2] - Send message" << std::endl;
        std::cout << "[3] - Exit the program" << std::endl;

        std::cin >> operationChoice;

        switch (operationChoice)
        {
        case 1:
            std::cout << "\nEnter the importance of the message: ";
            std::cout << "\n[1] - low," << "\n[2] - standart" << "\n[3] - high" << std::endl;
            std::cin >> levelInt;
            levelDefault = GetLogLevel(levelInt);
            if (!levelDefault.first)
            {
                std::cout << "Incorrect importance level value" << std::endl;
                continue;
            }
            logger->SetDefaultLevel(levelDefault.second);
            break;

        case 2:
            std::cout << "Enter message importance level: ";
            std::cout << "\n[1] - low," << "\n[2] - standart" << "\n[3] - high" << "\n[4] - default" << std::endl;
            std::cin >> levelInt;
            Lib::LoggerInterface::Level levelMsg;
            if (levelInt == 4)
            {
                levelMsg = levelDefault.second;
            }
            else
            {
                auto levelMsgTemp = GetLogLevel(levelInt);
                if (!levelMsgTemp.first)
                {
                    std::cout << "Incorrect importance level value" << std::endl;
                    continue;
                }
                levelMsg = levelMsgTemp.second;
            }

            std::cout << "Enter your message: ";
            std::cin.ignore();
            std::getline(std::cin, message);

            logger->Log(message.c_str(), levelMsg);
            break;

        case 3:
            std::cout << "The program is terminating its work." << std::endl;
            execution = false;
            continue;

        default:
            std::cout << "Input error!" << std::endl;
            continue;
        }
    }
    return 0;
}
