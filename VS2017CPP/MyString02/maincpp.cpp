#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include<iostream>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<numeric>
#include "MyString.h"
using namespace std;

//1.在 32 位编译器默认情况下, sizeof(a)等于（  ）字节？
//class a
//{
//public:
//	virtual void funa();
//	virtual void funb();
//	void fun();
//	static void fund();
//	static int si;
//private:
//	int i;
//	char c;
//};
//  F. 12
//在VC++下是 12. 这里需要考虑三个问题
//一是虚函数表vtable的入口表地址vpointer(缩写vptr)
//二是字节对齐.
//三是静态成员是所有对象共享, 不计入sizeof空间.
//在大部分C++的实现中, 带有虚函数的类的前4个BYTE是虚函数vtable表的这个类入口地址.所以sizeof必须要加入这个4个byte的长度, 除此外, 类的sizoef()为所有数据成员总的sizeof之和, 这里是int i, 和char c.其中char c被字节对齐为4.这样总长度为
//Sizeof(a) = sizeof(vtable)+size(int) + sizeof(char + 字节对其) = 12;

//2假设A为抽象类，下列声明（   ）是正确的。(2分)

//
//B、A *p;
//

//在设计时，常常希望基类仅仅作为其派生类的一个接口。这就是说，仅想对基类进行向上类型转换，使用它的接口，而不希望用户实际的创建一个基类的对象。同时创建一个纯虚函数允许接口中放置成员原函数，而不一定要提供一段可能对这个函数毫无意义的代码。
//
//做到这点，可以在基类中加入至少一个纯虚函数(pure virtual function), 使得基类称为抽象类(abstract class).
//纯虚函数使用关键字virtual，并在其后面加上 = 0。如果试图去实例化一个抽象类，编译器则会阻止这种操作。
//当继承一个抽象类的时候，必须实现所有的纯虚函数，否则由抽象类派生的类也是一个抽象类。
//Virtual void fun() = 0; 告诉编译器在vtable中为函数保留一个位置，但在这个特定位置不放地址。
//
//建立公共接口目的是为了将子类公共的操作抽象出来，可以通过一个公共接口来操纵一组类，且这个公共接口不需要事先(或者不需要完全实现)。可以创建一个公共类.

//3.假定CSomething是一个类，执行下面这些语句之后，内存里创建了（   ）个CSomething对象。
//
//CSomething a();// 只是个函数声明
//CSomething a;创建一个类的对象
//CSomething b(2);// +1
//
//CSomething c[3];// +3，对象数组
//
//CSomething &ra = b;// 引用，没有新构造
//
//CSomething d = b;// +1，调用拷贝构造函数
//
//CSomething *pA = c;// 只是给指针赋值
//
//CSomething *p = new CSomething(4);// +1，构造并给指针赋值
//
//(2分)
//E、6

//4.如果有如下函数模板的定义：
//template <class T>
//T func(T x, T y)
//{
//	return x + y;
//}
//则对函数func调用不正确的是（   ）。
//c.func(3, 2.5)
//函数模板不允许自动类型转换，必须严格匹配类型
//普通函数可以进行自动类型转换

//5.已知在类B中已经重载了--、 = 、 + 、[]运算符，则其中肯定属于成员函数运算符的是（  ）。(2分)
//
//D、= 和[]
//= , [], () 和->操作符只能通过成员函数进行重载

//6.下列关于类的继承描述中，（  ）是错误的。(2分)//参考答案貌似是错的
//派生类可以访问基类的所有数据成员，也能调用基类的所有成员函数

//派生类继承基类，派生类拥有基类中全部成员变量和成员方法（除了构造和析构之外的成员方法），但是在派生类中，继承的成员并不一定能直接访问，不同的继承方式会导致不同的访问权限。

//7若有以下定义和语句：int w[2][3]，（*pw）[3] ； pw=w ； 则对w 数组元素非法引用是_____
//B. *(pw + 1)[2]

//*(w[0] + 2)
////选项A表示元素w[0][2]
//
//*(pw + 1)[2]
//
//
//pw[0][0]
////选项C表示元素w[0][0]
//
//*(pw[1] + 2)
//选项D表示元素w[1][2]
//而选项B中pw + 1表示第2行元素的地址，(pw + 1)[2]相当于(pw + 1) + 2，表示第4行元素的地址，显然超出该二维数组的范围。

//8以下语句中，输出结果与众不同的一个是（   ）。(2分)
void test8()
{
	cout << "1. " << setfill(' ') << "Hello! " << endl;

	cout << "1. " << ' ' << "Hello! \n";//b选项

	cout << "1. Hello! " << endl;

	cout << "1. " << setw(7) << "Hello! ";
	cout << endl;
}

//9 .有一个类A，其数据成员如下：
//
//class A {
//
//	...
//
//private:
//
//	int a;
//
//public:
//
//	const int b;
//
//	float* &c;
//
//	static const char* d;
//
//	static double* e;
//
//};
//则构造函数中，成员变量一定要通过初始化列表来初始化的是（  ）
//B.  b c
//初始化成员列表(参数列表)只能在构造函数使用。
//《C++ Primer》（第5版 P259）中提到在以下三种情况下需要使用初始化成员列表：
//1、const常量成员，因为常量只能初始化，不能赋值，所以必须放在初始化列表中；
//2、引用类型的成员，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表中；
//3、成员类型是没有默认构造函数的类。若没有提供显示初始化式，则编译器隐式使用成员类型的默认构造函数，若类没有默认构造函数，则编译器尝试使用默认构造函数将会失败。
//注意：
//C++初始化类成员时，是按照声明的顺序初始化的，而不是按照出现在初始化列表中的顺序。所以要特别注意，保证两者顺序一致才能真正保证其效率和准确性。

//10.double r = 99, *p = &r ;
//*p = r;
//则以下正确的叙述是_ 。
//D .语句"*p=r;"取变量r 的值放回r 中
void test10()
{
	double r = 99;
	double *p = &r;

	cout << r << endl;
	cout << *p << endl;
	cout << p << endl;

	*p = r;
	cout << *p << endl;
}

//11 . 已知如下函数, 则程序输出的结果正确的是 （  ）。

class A {
public:
	A() { cout << "constructor  A "; }
};
class B :public A {
public:
	B() { cout << "constructor  B "; }
};

void test11()
{
	B b;
}
//C、constructor A constructor B

//12.下面代码的输出结果是（  ）。
void test12()
{
	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 };
	char *p;

	int i;

	i = 8;

	p = a + i;

	printf("%s\n", p - 3);
}

//13.设有如下定义:

//struct snow
//{
//	int a;
//
//	float b;
//
//}c2, *p;
//若有p = &c2; 则对c2中的成员a的正确引用是:（  ）
//
//B.(*p).a
//. 运算符访问结构体或类 变量的 成员.
//->运算符访问结构体或类 指针 变量的 成员.

//14. 设置虚基类的目的是（  ）。
//A 简化程序
//B 消除二义性
//C 提高运行效率
//D 减少目标代码
//虚基类是为了强调"这个类型的某些方法没有意义, 只是为了继承, 不要构造这种类型的对象"

//15. 定义 char **a[3][4], 在32位系统下则变量占有的内存空间为（  ）。(2分)

//C、48

//3*4*4=48

//16. 简述指针与引用的区别。
//
//
//a)引用创建的同时必须初始化，即引用必须引用一个具体的对象。指针创建的时候可以不必初始化。
//
//b)不存在空引用，但是存在NULL指针。
//
//c)引用在初始化之后，不可改变改变为引用其他对象，指针可以改变指向。
//
//d)语言层面，引用的用法和对象一样；在二进制层面，引用一般都是通过指针来实现的。

//17、简述C++中多态的实现步骤。(5分)
//
//a)父类中要有虚函数或纯虚函数。
//
//b)子类重写父类中的虚函数。
//
//c)父类的指针或引用指向子类的对象，并通过父类的指针或引用调用虚函数。

bool greaterThan5(int val)
{
	return val > 5;
}
//要求：
//（1）将ia复制到一个vector容器vec中和一个list容器中lst中。
//（2）将vec容器中的奇数值元素删除。
//（3）使用内置算法(accumulate)计算vec窗器所有元素的和。
//（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。
//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
void test17()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
	//(1)将ia复制到一个vector容器vec中和一个list容器中lst中。
	vector<int> vec(ia, ia + sizeof(ia) / sizeof(int)); ////将v[begin(), end())区间中的元素拷贝给本身。
	list<int>lst(ia, ia + sizeof(ia) / sizeof(int));
	//遍历，查看复制结果
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	//遍历链表,查看结果
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	cout << "================华丽==================" << endl;
	//（2）将vec容器中的奇数值元素删除。
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it % 2 != 0)//是奇数就删除，然后再重头遍历
		{
			vec.erase(it);
			it = vec.begin();
		}
	}
	if (*(vec.begin()) % 2 != 0)//再检查一下首个元素是否为奇数，是的话就删除
	{
		vec.erase(vec.begin());
	}
	cout << endl;
	//遍历，检查删除结果
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//（3）使用内置算法(accumulate)计算vec窗器所有元素的和。
	int sum = accumulate(vec.begin(), vec.end(), 0);// 计算容器元素累计总和(容器开始迭代器,容器结束迭代器,累加值)
	cout << "accumulate:" << sum << endl;

	//（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。
	int n = count_if(lst.begin(), lst.end(), greaterThan5); //统计元素出现次数(容器开始迭代器,容器结束迭代器,谓词)
	cout << "大于5的元素个数:" << n << endl;
}

void test18()
{
	//有参构造
	MyString str1("hello world.");
	//重载<<
	cout << str1 << endl;

	//重载>>
	cin >> str1;
	cout << str1 << endl;

	//拷贝构造
	MyString str2(str1);
	cout << str2 << endl;

	////赋值运算符重载
	MyString str3;
	str3 = str1;
	str3 = "abcd";
	cout << str3 << endl;

	////[]
	//cout << str1[2] << endl;

	////+
	MyString str4;
	cout << str4 + str1 << endl;
	cout << str4 + "123" << endl;
	cout << str1 + "123" << endl;

	//==
	MyString str5("hello world,.");
	if (str5 == str1)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
	MyString *pStr = new MyString("hello world");
	cout << *pStr << endl;
}

#pragma pack(2)
void test19()
{
	class A
	{
		int i;
		union U
		{
			char buff[13];
			int i;
		}u;
		void foo() {    }
		typedef char* (*f)(void*);
		enum { red, green, bule } color;
	}a;

	cout << sizeof(a) << endl;
}

void  swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << '-' << b << '\n';
}
void test20()
{
	int x = 1;
	int y = 2;
	swap(x, y);
	cout << x << '-' << y << '\n';
}

void test21()
{
	struct Test {
		int a;//4
		char b;//2
		short c;//1
	};
	cout << sizeof(Test);//8
}

int main()
{
	//test8();
	test19();
	//test11();
	//cout << endl;
	//test12();

	system("pause");
	return EXIT_SUCCESS;
}