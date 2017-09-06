#include <iostream>
#include <string>
#include <Windows.h>
#include <iostream> // std::cout
#include <thread>   // std::thread

using namespace std;

#define num_threads 10;

void thread_task()
{
	cout << "hello thread" << endl;
}

void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}

int SetTextColor(string str)
{
	int i, j;
	while (cin >> i >> j)
	{
		SetColor(i, j);
		cout << str << endl;
		SetColor(7, 0);
	}
	return 0;
}

int main()
{
	std::thread t[10];
	for (int i = 0; i < 10; ++i)
	{
		t[i] = std::thread(thread_task);
	}
	std::cout << "Launched from the mainn___join start" << endl;
	for (int i = 0; i < 10; ++i)
	{
		t[i].join();
	}
	std::cout << "Launched from the mainn___join end" << endl;

	getchar();
	return 0;
}

/*
get_id
获取线程 ID。
joinable
检查线程是否可被 join。
join
Join 线程。
detach
Detach 线程
swap
Swap 线程 。
native_handle
返回 native handle。
hardware_concurrency [static]
检测硬件并发特性。
*/