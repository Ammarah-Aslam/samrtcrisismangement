#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main() {
  

    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // 2️⃣ Create socket

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // 3️⃣ Server address setup

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);       // PORT
    serverAddr.sin_addr.s_addr = INADDR_ANY; // localhost

    // 4️⃣ Bind
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // 5️⃣ Listen
    listen(serverSocket, 1);
    cout << "Server started... Waiting for client..." << endl;

    // 6️⃣ Accept
    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);

    cout << "Client connected successfully!" << endl;

    // 7️⃣ Send message to client

    const char* msg = "Connected to C++ Server";
    send(clientSocket, msg, strlen(msg), 0);

    // 8️⃣ Close sockets

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
