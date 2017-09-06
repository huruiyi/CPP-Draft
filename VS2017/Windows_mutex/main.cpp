#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
int g_num = 0;
mutex g_num_mutex;

void slow_increment(int id)
{
	for (int i = 0; i < 50; ++i)
	{
		g_num_mutex.lock();
		++g_num;
		cout << id << " => " << g_num << endl;
		g_num_mutex.unlock();

		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

int main()
{
	thread t1(slow_increment, 0);
	thread t2(slow_increment, 1);
	t1.join();
	t2.join();

	getchar();
}