#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <sstream>

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

mutex cout_mutex;
timed_mutex mutexv;

void job(int id)
{
	using Ms = chrono::milliseconds;
	ostringstream stream;

	for (int i = 0; i < 3; ++i)
	{
		if (mutexv.try_lock_for(Ms(100)))
		{
			stream << "success ";
			this_thread::sleep_for(Ms(100));
			mutexv.unlock();
		}
		else {
			stream << "failed ";
		}
		this_thread::sleep_for(Ms(100));
	}

	lock_guard<mutex> lock(cout_mutex);
	cout << "[" << id << "] " << stream.str() << "\n";
}

int main()
{
	thread t1(slow_increment, 0);
	thread t2(slow_increment, 1);
	t1.join();
	t2.join();

	vector<thread> threads;
	for (int i = 0; i < 4; ++i)
	{
		threads.emplace_back(job, i);
	}

	for (auto& i : threads)
	{
		i.join();
	}

	getchar();
}