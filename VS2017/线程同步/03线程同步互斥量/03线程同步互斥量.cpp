#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;

//int g_num = 0;
//mutex g_num_mutex;
//
//void slow_increment(int id)
//{
//	for (int i = 0; i < 50; ++i)
//	{
//		g_num_mutex.lock();
//		++g_num;
//		cout << id << " => " << g_num << endl;
//		g_num_mutex.unlock();
//
//		this_thread::sleep_for(chrono::milliseconds(1));
//	}
//}
//
//int main()
//{
//	thread t1(slow_increment, 0);
//	thread t2(slow_increment, 1);
//	t1.join();
//	t2.join();
//
//	getchar();
//}

std::mutex cout_mutex; // control access to std::cout
std::timed_mutex mutexv;

void job(int id)
{
	using Ms = std::chrono::milliseconds;
	std::ostringstream stream;

	for (int i = 0; i < 3; ++i) {
		if (mutexv.try_lock_for(Ms(100)))
		{
			stream << "success ";
			std::this_thread::sleep_for(Ms(100));
			mutexv.unlock();
		}
		else {
			stream << "failed ";
		}
		std::this_thread::sleep_for(Ms(100));
	}

	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << "[" << id << "] " << stream.str() << "\n";
}

int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 4; ++i) {
		threads.emplace_back(job, i);
	}

	for (auto& i : threads) {
		i.join();
	}

	getchar();
}