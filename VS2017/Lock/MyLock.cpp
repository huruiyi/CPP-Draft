#include <iostream>
#include <process.h>
#include "Lock.h"
using namespace std;
//����һ���������
Mutex g_Lock;
//�̺߳���
unsigned int __stdcall StartThread(void *pParam)
{
	char *pMsg = (char *)pParam;
	if (!pMsg)
	{
		return (unsigned int)1;
	}
	//�Ա�������Դ�����´�ӡ��䣩�Զ�����
	//�̺߳�������ǰ���Զ�����
	CLock lock(g_Lock);
	for (int i = 0; i < 5; i++)
	{
		cout << pMsg << endl;
		Sleep(500);
	}
	return (unsigned int)0;
}
int main(int argc, char* argv[])
{
	HANDLE hThread1, hThread2;
	unsigned int uiThreadId1, uiThreadId2;
	char *pMsg1 = "First print thread.";
	char *pMsg2 = "Second print thread.";
	//�������������̣߳��ֱ��ӡ��ͬ����Ϣ
	//hThread1 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StartThread, (void *)pMsg1, 0, (LPDWORD)&uiThreadId1);
	//hThread2 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StartThread, (void *)pMsg2, 0, (LPDWORD)&uiThreadId2);
	hThread1 = (HANDLE)_beginthreadex(NULL, 0, &StartThread, (void *)pMsg1, 0, &uiThreadId1);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, &StartThread, (void *)pMsg2, 0, &uiThreadId2);
	//�ȴ��߳̽���
	DWORD dwRet = WaitForSingleObject(hThread1, INFINITE);
	if (dwRet == WAIT_TIMEOUT)
	{
		TerminateThread(hThread1, 0);
	}
	dwRet = WaitForSingleObject(hThread2, INFINITE);
	if (dwRet == WAIT_TIMEOUT)
	{
		TerminateThread(hThread2, 0);
	}
	//�ر��߳̾�����ͷ���Դ
	::CloseHandle(hThread1);
	::CloseHandle(hThread2);
	system("pause");
	return 0;
}