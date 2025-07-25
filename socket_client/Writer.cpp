#include "Lib.h"

#include <cstring>
#include <chrono>
#include <thread>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LOCAL_PORT 48000
#define REMOTE_PORT 48001

int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in localAddr, remoteAddr;

    std::memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = INADDR_ANY;
    localAddr.sin_port = htons(LOCAL_PORT);
    bind(sock, (const sockaddr *)&localAddr, sizeof(localAddr));

    memset(&remoteAddr, 0, sizeof(remoteAddr));
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(REMOTE_PORT);
    remoteAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sock, (const struct sockaddr *)&remoteAddr, sizeof(remoteAddr));

    auto *logger = Lib::CreateLoggerSocket(sock, Lib::LoggerInterface::Level::STANDART);
    for (int i = 0; i < 100; i++)
    {
        logger->Log("Hello", Lib::LoggerInterface::Level::HIGH);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    Lib::DeleteLoggerSocket(logger);
    close(sock);
}