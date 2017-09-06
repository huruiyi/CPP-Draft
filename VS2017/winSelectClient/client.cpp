#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.H>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_ADDRESS      "127.0.0.1"
#define SERVER_PORT         8000

#define SOCKET_NUM          2000       /// 客户端socket的个数,修改该值可以改变连接到服务器的客户端个数

int main()
{
	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) return 1;

	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		std::cout << "WSAStartup() error." << std::endl;
		return -1;
	}

	SOCKET allSocketClients[SOCKET_NUM];
	for (int i = 0; i < SOCKET_NUM; i++)
	{
		SOCKET socketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (socketClient == INVALID_SOCKET)
		{
			WSACleanup();
			std::cout << "socket() error." << std::endl;
			return -1;
		}
		allSocketClients[i] = socketClient;
	}

	SOCKADDR_IN server;
	memset(&server, 0, sizeof(SOCKADDR_IN));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	inet_pton(server.sin_family, SERVER_ADDRESS, &server.sin_addr);

	for (int i = 0; i < SOCKET_NUM; i++)
	{
		SOCKET socketClient = allSocketClients[i];
		err = connect(socketClient, (struct sockaddr *)&server, sizeof(SOCKADDR_IN));
		if (err == SOCKET_ERROR)
		{
			std::cout << "connect() error." << std::endl;
			closesocket(socketClient);
			WSACleanup();
			return -1;
		}

		std::cout << "第 " << i + 1 << " 个客户端连接服务器成功。" << std::endl;
	}

	for (int i = 0; i < SOCKET_NUM; i++)
	{
		SOCKET socketClient = allSocketClients[i];
		char message[100] = { 0 };
		sprintf_s(message, "我是第 %d 个客户端 ", i + 1);
		send(socketClient, message, strlen(message), 0);
	}

	/// 按 q 退出程序
	do
	{
	} while (getchar() != 'q');

	for (int i = 0; i < SOCKET_NUM; i++)
	{
		SOCKET socketClient = allSocketClients[i];
		closesocket(socketClient);
	}

	WSACleanup();

	return 0;
}