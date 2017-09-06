#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

//class a
//{
//public:
//    virtual void funa();
//    virtual void funb();
//    void fun();
//    static void fund();
//    static int si;
//private:
//    int i;
//    char c;
//};

//class A
//{
//public:
//    A()
//    {
//    }
//    A(int a)
//    {
//    }
//    virtual int func() = 0;
//};

class CSomething
{
public:
	CSomething()
	{
		cout << "CSomething()" << endl;
	};
	CSomething(int a) {
		cout << "CSomething(int a)" << endl;
	};

	~CSomething()
	{
		cout << "XXXX" << endl;
	}
};

template <class T>
T func(T x, T y)
{
	return x + y;
}

class AA
{
private:
	int a;
public:
	const int b;
	float* &c;
	static const char* d;
	static double* e;
};

class A
{
public:
	A()
	{
		cout << "constructor  A ";
	}
};

class B :public A
{
public:
	B()
	{
		cout << "constructor  B ";
	}
};

struct snow
{
	int a;
	float b;
}c2, *p;

/*
函数功能:统计字符串中数字个数
函数参数:str：指向所要求数字字符个数的字符串；
pCount：将所求数字字符个数通过pCount进行间接赋值。
函数返回值: 成功返回0 失败返回-1
*/

int main()
{
	/*  p = &c2;

	(*p).c2.a;
	(*p).a;
	p->c2.a;
	p.c2.a;*/

	p = &c2;

	char **a[3][4];
	cout << sizeof(a) << endl;

	//char a[10] = { '1','2','3','4','5','6','7','8','9',0 }, *p;
	//int i;
	//i = 8;
	//p = a + i;
	//printf("%s\n", p - 3);

	B b;

	/*  double r = 99;
	double *p = &r;
	*p = r;
	cout << r << endl;
	cout << *p << endl;*/

	/*cout << "[" << "1. " << setfill(' ') << "Hello! " << "]" << endl;
	cout << "[" << "1. " << ' ' << "Hello!" << "]" << "\n";
	cout << "[" << "1. Hello! " << "]" << endl;
	cout << "[" << "1. " << setw(7) << "Hello! " << "]";*/

	//int w[2][3] = { 1,2,3,4,5,6 };
	//int(*pw)[3];
	//pw = w;
	//cout << *(w[0] + 2) << endl;
	//cout << *(pw + 1)[2] << endl;//error
	//cout << pw[0][0] << endl;
	//cout << *(pw[1] + 2) << endl;

	/*   func(3, 5);
	func<>(3, 5);
	func(3, 2.5);//error
	func<int>(3, 2.5);*/

	//CSomething a();

	//CSomething b(2);
	//CSomething &ra = b;
	//CSomething d = b;

	//CSomething c[3];
	//CSomething *pA = c;

	//CSomething *p = new CSomething(4);

	//A fun(int);
	//A *p;
	//int fun(A);
	//A Obj;
	// cout << sizeof(a) << endl;
	system("pause");
	return 0;
}