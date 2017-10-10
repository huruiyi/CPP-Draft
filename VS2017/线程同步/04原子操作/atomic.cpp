#include <iostream>
#include <string>
#include <atomic>
#include <chrono>
#include <thread>
#include<mutex>

using namespace std;
std::atomic_int   atoint = 0;
std::atomic<int> aint(10000);
int inum = 0;
void slow_increment()
{
	for (int i = 0; i < 1000000; i++)
	{
		atoint++;
		inum++;
	}
}
static void func(static int tag) 
{
	cout << tag << endl;
};

int main()
{
	int aaaa = 100;
	for (size_t i = 0; i < 100; i++)
	{
		func(aaaa++);
	}
	atomic_init(&atoint, 1000000);

	thread t1(slow_increment);
	thread t2(slow_increment);

	t1.join();
	t2.join();
	printf("%d\n", inum);
	printf("%d\n", (int)atoint);

	getchar();
	return 0;
}