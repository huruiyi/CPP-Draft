#include <iostream>
#include<Windows.h>
using namespace std;

int main()
{
	cout << std::hex << "ʮ������" << GetCurrentThreadId() << endl;
	cout << std::dec << "ʮ  ����" << GetCurrentThreadId() << endl;
	cout << GetCurrentThread() << endl;

	system("pause");
}