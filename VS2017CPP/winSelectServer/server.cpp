#include <WS2tcpip.h>
#include <WinSock2.H>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	/// ��ʼ��socket
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 2);
	int result = 0;
	result = WSAStartup(version, &wsaData);
	if (result != 0)
	{
		std::cout << "WSAStartup() error." << std::endl;
		return -1;
	}

	/// ����socket
	SOCKET socketListen;
	socketListen = socket(AF_INET, SOCK_STREAM, 0);
	if (socketListen == INVALID_SOCKET)
	{
		WSACleanup();
		std::cout << "socket() error." << std::endl;
		return -1;
	}

	/// ��������ַ�ṹ
	sockaddr_in svrAddress;
	svrAddress.sin_family = AF_INET;
	svrAddress.sin_addr.s_addr = INADDR_ANY;
	svrAddress.sin_port = htons(8000);

	/// �󶨷������׽���
	result = bind(socketListen, (sockaddr*)&svrAddress, sizeof(svrAddress));
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		std::cout << "bind() error." << std::endl;
		return -1;
	}

	/// ��������
	result = listen(socketListen, 5);
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		std::cout << "listen() error." << std::endl;
		return -1;
	}
	std::cout << "�����������ɹ��������˿ڣ�" << ntohs(svrAddress.sin_port) << std::endl;

	/// selectģ��
	fd_set allSockSet;
	FD_ZERO(&allSockSet);

	FD_SET(socketListen, &allSockSet); // ��socketListen�����׽��ּ�����

	while (true)
	{
		fd_set readSet;
		FD_ZERO(&readSet);
		readSet = allSockSet;

		result = select(0, &readSet, NULL, NULL, NULL);
		if (result == SOCKET_ERROR)
		{
			std::cout << "listen() error." << std::endl;
			break;
		}

		if (FD_ISSET(socketListen, &readSet))
		{
			sockaddr_in clientAddr;
			int len = sizeof(clientAddr);

			SOCKET clientSocket = accept(socketListen, (sockaddr*)&clientAddr, &len);
			if (clientSocket == INVALID_SOCKET)
			{
				std::cout << "accept() error." << std::endl;
				break;
			}
			FD_SET(clientSocket, &allSockSet);   /// ���´������׽��ּ��뵽������

			char ipAddress[16] = { 0 };
			inet_ntop(AF_INET, &clientAddr, ipAddress, 16);
			std::cout << "���µ�����[" << ipAddress << ":" << ntohs(clientAddr.sin_port) << "], Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;

			continue;
		}

		for (u_int i = 0; i < allSockSet.fd_count; ++i)
		{
			SOCKET socket = allSockSet.fd_array[i];

			sockaddr_in clientAddr;
			int len = sizeof(clientAddr);
			getpeername(socket, (struct sockaddr *)&clientAddr, &len);
			char ipAddress[16] = { 0 };
			inet_ntop(AF_INET, &clientAddr, ipAddress, 16);

			/// �ɶ��Լ��ӣ��ɶ���ָ�����ӵ����������ݵ����������ѹرա����û���ֹ
			if (FD_ISSET(socket, &readSet))
			{
				char bufRecv[100];
				result = recv(socket, bufRecv, 100, 0);
				if (result == SOCKET_ERROR)
				{
					DWORD err = WSAGetLastError();
					if (err == WSAECONNRESET)       /// �ͻ��˵�socketû�б������ر�,��û�е���closesocket
					{
						std::cout << "�ͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port) << "]��ǿ�йر�, ";
					}
					else
					{
						std::cout << "recv() error��" << std::endl;
					}

					closesocket(socket);
					FD_CLR(socket, &allSockSet);

					std::cout << "Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;
					break;
				}
				else if (result == 0)               /// �ͻ��˵�socket����closesocket�����ر�
				{
					closesocket(socket);
					FD_CLR(socket, &allSockSet);

					std::cout << "�ͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port)
						<< "]�Ѿ��˳���Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;
					break;
				}

				bufRecv[result] = '\0';
				std::cout << "���Կͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port)
					<< "]����Ϣ��" << bufRecv << std::endl;
			}
		}
	}

	for (u_int i = 0; i < allSockSet.fd_count; ++i)
	{
		SOCKET socket = allSockSet.fd_array[i];
		closesocket(socket);
	}

	WSACleanup();
	return 0;
}