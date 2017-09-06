#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.H>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_ADDRESS      "127.0.0.1"
#define SERVER_PORT         8000

#define SOCKET_NUM          2000       /// �ͻ���socket�ĸ���,�޸ĸ�ֵ���Ըı����ӵ��������Ŀͻ��˸���

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

		std::cout << "�� " << i + 1 << " ���ͻ������ӷ������ɹ���" << std::endl;
	}

	for (int i = 0; i < SOCKET_NUM; i++)
	{
		SOCKET socketClient = allSocketClients[i];
		char message[100] = { 0 };
		sprintf_s(message, "���ǵ� %d ���ͻ��� ", i + 1);
		send(socketClient, message, strlen(message), 0);
	}

	/// �� q �˳�����
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