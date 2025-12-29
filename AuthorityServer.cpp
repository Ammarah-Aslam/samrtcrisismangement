#include <iostream>
#include <winsock2.h>
#include "AuthorityIncidentManager.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {

    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 1);

    cout << "Authority Server Started..." << endl;

    AuthorityIncidentManager manager;

    while (true) {

        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);

        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);

        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);

        string msg(buffer);

        // Format: ADD|type|location|desc|severity
        if (msg.find("ADD") == 0) {

            string t, l, d;
            int s;

            sscanf(buffer, "ADD|%[^|]|%[^|]|%[^|]|%d",
                &t[0], &l[0], &d[0], &s);

            manager.addIncident(t, l, d, s);

            const char* reply = "Incident received & stored";
            send(clientSocket, reply, strlen(reply), 0);
        }
        closesocket(clientSocket);
    }
    WSACleanup();
    return 0;
}
