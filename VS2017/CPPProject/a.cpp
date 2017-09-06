#include<iostream>
#include<string>>

using namespace std;

class Person
{
public:
	string Name;
	int Age;
public:
	Person()
	{
	}
	Person(string name, int age)
	{
		this->Name = name;
		this->Age = age;
	}
	void ShowInfo()
	{
		cout << this->Name << "  " << this->Age << endl;
	}
	~Person() {}
};


template<typename T>
class ListNode
{
public:

	ListNode(T t)
	{
		data = t;
		next = NULL;
	}

	T data;
	ListNode * next;
protected:
private:
};

template<typename T>
class List
{
public:

	List()
	{
		cur = NULL;
	}

	ListNode<T> * cur;

	void pushback(ListNode<T> * node)
	{
		if (cur == NULL)
		{
			cur = node;
		}
		else
		{
			cur->next = node;

			cur = node;

			cur->next = NULL;
		}
	}

	ListNode<T> * GetEnd()
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}

		return cur;
	}

protected:
private:
};

typedef ListNode<int> _listnode;
typedef List<int> _list;

void test1()
{
	//判断2个单向链表的是否有交叉点
	_list mylist, mylist2;

	for (int i = 0; i<10; i++)
	{
		_listnode *p = new _listnode(i);

		mylist.pushback(p);

		if (i == 5)
		{
			mylist2.pushback(p);
		}
	}

	printf("end data=%d\n", mylist.GetEnd()->data);

	printf("end data=%d\n", mylist2.GetEnd()->data);

	if (mylist2.GetEnd() == mylist.GetEnd())
	{
		printf("same end node\n");
	}

	getchar();
}
int main()
{
	test1();

	getchar();
	return 0;
}