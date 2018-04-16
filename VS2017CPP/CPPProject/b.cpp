#include <iostream>
#include<Windows.h>
using namespace std;

int main()
{
	cout << std::hex << "十六进制" << GetCurrentThreadId() << endl;
	cout << std::dec << "十  进制" << GetCurrentThreadId() << endl;
	cout << GetCurrentThread() << endl;

	system("pause");
}