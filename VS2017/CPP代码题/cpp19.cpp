#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
using namespace std;
/*
 （STL）两个栈实现⼀个队列。
要求：只能使用栈的pop(),top()和push()，以及测试栈是否为空
empty()四个操作.

来实现队列的clear(), push(),pop(),back(),front()等操作。
 */

template<class T>
class MDeque
{
public:
	T frontv = 0;;
	bool IsFirst = true;
	void clear()
	{
		frontv = NULL;
		while (!sin.empty())
		{
			sin.pop();
		}
		while (!sout.empty())
		{
			sout.pop();
		}
	}
	void push(T t)
	{
		if (IsFirst)
		{
			frontv = t;
		}

		sin.push(t);
		sout.push(sin.top());
		sin.pop();
		IsFirst = false;
	}
	void pop()
	{
		sout.pop();
		//   push(sout.top());
	}
	T back()
	{
		if (sout.empty())
		{
			return NULL;
		}
		return sout.top();
	}

	T    front()
	{
		return frontv;
	}
private:
	//pop(),top()和push() empty
	stack<T> sin;//入
	stack<T> sout;//出
};

void foreachMd(MDeque<int> d)
{
	while (d.back())
	{
		cout << d.back() << endl;
		d.pop();
	}
}
int main19()
{
	MDeque<int> md;
	md.push(1);
	md.push(2);
	md.push(3);
	md.push(4);
	md.push(5);
	cout << "1:...........................................\n" << endl;
	foreachMd(md);
	//clear(), push(), pop(), back(), front()
	md.clear();
	cout << "2:.................................\n" << endl;

	foreachMd(md);
	cout << "3:................................\n" << endl;
	md.push(6);
	foreachMd(md);

	cout << "XXXXXXXXXXX" << endl;
	md.pop();
	cout << md.front() << endl;
	cout << md.back() << endl; //ok
	system("pause");
	return 0;
}