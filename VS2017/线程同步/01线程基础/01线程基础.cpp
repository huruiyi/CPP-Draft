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

int a = 0;
void f1()
{
	for (int i = 0; i < 10000000; ++i)
	{
		a++;
	}
}

void f2()
{
	for (int i = 0; i < 50000000; ++i)
	{
		a++;
	}
}

int main()
{
#if 0
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
#endif // 0

#if 1
	std::thread t1(f1);
	std::thread t2(f2);
	t1.join();
	t2.join();

	std::thread t3(f1);
	t3.join();
	std::thread t4(f2);
	t4.join();
 
	printf("%d\n", a);
#endif // 0

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