#include<iostream>
#include<thread>
#include<chrono>

#include<Windows.h>
#include<process.h>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
	}
	static Singleton * single;
public:
	static Singleton * GetSingelton()
	{
		if (single == NULL)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << "产生一个示例(懒汉式)" << endl;
			single = new Singleton();
		}
		return single;
	}
};

Singleton *  Singleton::single = NULL;

void threadCallBack(void *p)
{
	Singleton::GetSingelton();
}
int main()
{
	//Singleton * single1 = Singleton::GetSingelton();
	//Singleton * single2 = Singleton::GetSingelton();
	//cout << (single1 == single2 ? "相等" : "不相等") << endl;

#if 0 "非线程安全"
	thread *th[50];
	int index[50] = { 0 };
	for (size_t i = 0; i < 50; i++)
	{
		index[i] = 0;
		th[i] = new thread([] {Singleton::GetSingelton(); });
	}
	for (size_t i = 0; i < 50; i++)
	{
		th[i]->join();
	}
#endif

	int threadnum = 3;
	HANDLE threadId[100];
	for (int i = 0; i < threadnum; i++)
	{
		threadId[i]=(HANDLE)_beginthread(threadCallBack, 0, (void *)NULL);
	}
	for (int i = 0; i < threadnum; i++)
	{
		WaitForSingleObject(threadId[i], INFINITE);
	}
	getchar();
	return 0;
}