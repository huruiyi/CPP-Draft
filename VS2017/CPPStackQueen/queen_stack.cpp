#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;


void QueenDemo()
{
	queue<int> q0;
	q0.push(11);
	q0.push(22);
	q0.push(33);

	queue<int> q;
	q.emplace(111);
	q.emplace(333);
	q.emplace(666);
	q.swap(q0);
	for (size_t i = 0; i < 10; i++)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		cout << "size:" << q.size() << "	back:" << q.back() << "		front:" << q.front() << endl;
		q.pop();
	}

	cout << "============================================================" << endl;
	while (!q0.empty())
	{
		cout << "size:" << q0.size() << "	back:" << q0.back() << "		front:" << q0.front() << endl;
		q0.pop();
	}
}


void StackDemo()
{
	stack<int> s0;
	s0.push(11);
	s0.push(22);
	s0.push(33);

	stack<int> s1;
	s1.emplace(111);
	s1.emplace(333);
	s1.emplace(666);
	s1.swap(s0);
	for (size_t i = 0; i < 10; i++)
	{
		s1.push(i);
	}

	while (!s1.empty())
	{
		cout << "size:" << s1.size() << "	top:" << s1.top() <<  endl;
		s1.pop();
	}

	cout << "============================================================" << endl;
	while (!s0.empty())
	{
		cout << "size:" << s0.size() << "	top:" << s0.top() << endl;
		s0.pop();
	}
}


//（STL）两个栈实现⼀个队列。
//要求：只能使用栈的pop(), top()和push()，以及测试栈是否为空
//empty()四个操作.来实现队列的clear(), push(), pop(), back(), front()等操作。
int main(int argc, char * argv[])
{
	StackDemo();
	getchar();
	return 0;
}