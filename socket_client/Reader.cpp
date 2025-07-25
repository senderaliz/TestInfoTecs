#include <cstring>
#include <iostream>
#include <chrono>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LOCAL_PORT 48001
#define REMOTE_PORT 48000

int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in localAddr, remoteAddr;

    std::memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = INADDR_ANY;
    localAddr.sin_port = htons(LOCAL_PORT);
    bind(sock, (const sockaddr *)&localAddr, sizeof(localAddr));
    char buffer[1024];
    auto timeStart = std::chrono::system_clock::now();
    while (true)
    {
        auto recvLen = recv(sock, buffer, 1024, MSG_DONTWAIT);
        if (recvLen > 0)
        {

            buffer[recvLen] = '\0';
            std::cout << buffer << std::endl;
        }
        auto timeNow = std::chrono::system_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(timeNow - timeStart).count();
        if (seconds >= 100)
        {
            break;
        }
    }
    close(sock);
}