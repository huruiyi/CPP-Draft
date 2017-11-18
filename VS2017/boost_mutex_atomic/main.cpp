#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/thread/thread.hpp>
#include <boost/atomic.hpp>
#include <boost/smart_ptr/detail/spinlock.hpp>
#include "time.h"

//��һ��������Դ������£�
//��������ļ��ԣ�ֻ��++�����߳����
//���߳�������֮�����ǽ������
//atomicԭ�Ӳ�����ʱ�Գ���������ԭ�Ӳ����Ĺ�ϵ�������ȷ
//mutex ������ʧ�Ƚϴ�Ϊatomic��4�����ң���Ȼ��֤�˽������ȷ�ԣ����Ǻ�ʱȴ��ԭ����10�౶
//boost spinlockЧ�ʵ���ˣ���̫����ϸ�ڣ������о�һ��
//���������Ĺ�ϵ�������ں�̬���û�̬�л��Ĺ�ϵ��
//�����׵Ĵ���ָ��
//������һ����Լ����˸��ѣ��ڲ��˽������Ƶ�����»��ǵ�����

long total = 0;
boost::atomic_long total2(0);
boost::mutex m;
boost::detail::spinlock sp;

void thread_click()
{
	for (int i = 0; i < 10000000; ++i)
	{
		++total;
	}
}

void mutex_click()
{
	for (int i = 0; i < 10000000; ++i)
	{
		m.lock();
		++total;
		m.unlock();
	}
}

void atomic_click()
{
	for (int i = 0; i < 10000000; ++i)
	{
		++total2;
	}
}

void spinlock_click()
{
	for (int i = 0; i < 10000000; ++i)
	{
		boost::lock_guard<boost::detail::spinlock> lock(sp);
		++total;
	}
}

int main()
{
	int thnum = 10;
	clock_t start = clock();
	boost::thread_group threads;
	for (int i = 0; i < thnum; ++i)
	{
		threads.create_thread(mutex_click);
	}
	threads.join_all();
	//��ʱ����
	clock_t end = clock();
	std::cout << "���߳�mutex�����" << total << std::endl;
	std::cout << "���߳�mutex��ʱ��" << end - start << std::endl;
	total = 0;
	start = clock();
	for (int i = 0; i < thnum; ++i)
	{
		threads.create_thread(thread_click);
	}
	threads.join_all();
	end = clock();
	std::cout << "���߳����������" << total << std::endl;
	std::cout << "���߳�������ʱ��" << end - start << std::endl;

	total = 0;
	start = clock();
	for (int i = 0; i < thnum; ++i)
	{
		threads.create_thread(atomic_click);
	}
	threads.join_all();
	end = clock();
	std::cout << "���߳�atomic�����" << total2 << std::endl;
	std::cout << "���߳�atomic��ʱ��" << end - start << std::endl;
	total = 0;
	start = clock();
	for (int i = 0; i < 10000000 * thnum; i++)
	{
		++total;
	}
	end = clock();
	std::cout << "���߳̽����" << total << std::endl;
	std::cout << "���̺߳�ʱ��" << end - start << std::endl;

	total = 0;
	start = clock();
	for (int i = 0; i < thnum; ++i)
	{
		threads.create_thread(spinlock_click);
	}
	threads.join_all();
	end = clock();
	std::cout << "�����������" << total << std::endl;
	std::cout << "��������ʱ��" << end - start << std::endl;
	getchar();
	return 0;
}