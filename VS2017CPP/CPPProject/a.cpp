#include<iostream>
#include<string>

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
	//�ж�2������������Ƿ��н����
	_list mylist, mylist2;

	for (int i = 0; i < 10; i++)
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

void test2()
{
	int oarry[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int darry[2][10] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int *ptrs[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		ptrs[i] = &oarry[i];
	}

	//int &refs[10];  //���������÷�����
	int(*y1)[10] = &oarry;//Parrayָ��һ������10������������
	int(*y2)[10] = darry;

	int(&p1)[10] = oarry;
	int *(&p2)[10] = ptrs; //arry����������ã������麬��10��ָ��
}

class A
{
public:
	int Aa;

	virtual ~A()
	{
		cout << "~A()" << endl;
	}
	virtual void FunA()
	{
		cout << "A: FunA()" << endl;
	}
};

class B :public A
{
public:
	int Ba;
	virtual void FunA() override
	{
		cout << "B: FunA()" << endl;
	}
	virtual ~B()
	{
		cout << "~B()" << endl;
	}
};

class base {
public:
	base() {}
	virtual ~base() = 0;
};

// Provide a definition for destructor.  
base::~base() {}

class derived :public base {
public:
	derived() {}
	~derived() {}
};

int maina()
{ 
	A *a = new B;
	a->FunA();
	((B *)a)->FunA();

	B *b = new B;
	b->FunA();

	char(*pchar)[10] = new char[2][10];
	delete[] pchar;

	A * as = new B[10];
	cout << "as�����С:" << sizeof(as) << endl;
	cout << "as�����С:" << sizeof(as[0]) << endl;
	cout << "as�����С:" << sizeof(as) / sizeof(as[0]) << endl;
	for (int i = 0; i < sizeof(as) / sizeof(as[0]); i++)
	{
	}

	getchar();
	return 0;
}