#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include <memory>

using namespace std;

struct SFoot { int x; };

class Fruit
{
public:
	Fruit(std::initializer_list<int>)
	{
	}
};

const int func_cint(void);
int& foo(int& i);
float foo(float& f);

const int func_cint(void)
{
	return 0;
}
int& foo(int& i)
{
	return i;
}
float foo(float& f)
{
	return 0;
}

template <typename T>
auto add(T &val) -> decltype(foo(val))
{
	return foo(val);
}
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
	return t + u;
}

int sum(const std::initializer_list<int>& list) {
	int total = 0;
	for (auto& e : list) {
		total += e;
	}

	return total;
}

void test1()
{
	decltype(func_cint()) fm = 0;
	const SFoot sfoot = SFoot();
	decltype(sfoot.x) a = 0;
	decltype((sfoot.x)) b = a; // 特别注意和上面的比较

	int n = 0, m = 0;
	decltype(m + n) c = 0;
	decltype(m += n) d = c;

	//template <typename val>
	//using str_map_t = std::map<std::string, val>;
	//str_map_t<int> mx1;
}

void test2()
{
	int a1 = { 1 }; // 虽然使用了等号，但它仍是列表初始化，私有的拷贝构造并不会影响它。
	int a21{ 1 };
	int *a3 = new int{ 123 };
	int *arr = new int[3]{ 1, 2, 3 };
}

void test3()
{
	auto list = { 1, 2, 3,4,5 };

	int a = sum(list);
	cout << a << endl;

	int b = sum({ 1, 2, 3,4 });
	cout << b << endl;

	int c = sum({});
	cout << c << endl;
}

struct MyStruct
{
	int a = 10;
	//auto b = 10;//不允许
	//static auto c = 10;//不允许
	static const auto d = 10;
};

template<typename T>
class TB
{
public:
	void	print(T t)
	{
		cout << __FUNCTION__ << "   " << t << endl;
	}
};

void autoDemo()
{
	TB<int> ta;
	ta.print(123);

	TB<string> tb;
	tb.print("123456");
	//TB<auto> tc = tb;//auto 不能推导模板参数的类型

	int fibarray[] = { 0, 1, 1, 2, 3, 5, 8, 13 };
	int len = sizeof(fibarray) / sizeof(fibarray[0]);
	for (int i = 0; i < len; i++)
	{
		std::cout << fibarray[i] << std::endl;
	}
	for (auto v : fibarray)
	{
		std::cout << v << std::endl;
	}
	for each (auto i in fibarray)
	{
		std::cout << i << std::endl;
	}

	Fruit fruit{ 1, 2, 3, 4 };

	cout << "vector<int> foreach............." << endl;
	vector<int> vr = { 1,2,3,4,5,6,7,8,9 };
	for (auto it = vr.begin(); it != vr.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for (auto v : vr)
	{
		cout << v << "\t";
	}
	cout << endl;
	for each (auto v in vr)
	{
		cout << v << "\t";
	}
	cout << endl;
}

void declTypeDemo()
{
	int x = 10;
	decltype(x) y = 9;
	decltype(x + y) z = 19;
	const int &i = x; //i const int
	decltype(i) j = y; //jconst int
}

void test4()
{
	{
		std::shared_ptr<int> shared_bad(new int[10]);
	} // the destructor calls delete, undefined behavior

	{
		std::shared_ptr<int> shared_good(new int[10], std::default_delete<int[]>());
	} // the destructor calls delete[], ok

	{
		std::unique_ptr<int> ptr(new int(5));
	} // unique_ptr<int> uses default_delete<int>

	{
		std::unique_ptr<int[]> ptr(new int[10]);
	} // unique_ptr<int[]> uses default_delete<int[]>

	  // default_delete can be used anywhere a delete functor is needed
	std::vector<int*> v;
	for (int n = 0; n < 100; ++n)
		v.push_back(new int(n));
	std::for_each(v.begin(), v.end(), std::default_delete<int>());
}

//c语音中函数没有初始化这一用法
void fun(int a, int b = 10, int c = 13)
{
}

class Test1
{
public:
	Test1(int n)
	{
		num = n;
	}//普通构造函数
private:
	int num;
};
class Test2
{
public:
	explicit Test2(int n)
	{
		num = n;
	}//explicit(显式)构造函数
private:
	int num;
};

void explicittest()
{
	Test1 t1 = 12;//隐式调用其构造函数,成功
	//Test2 t2 = 12;//编译错误,不能隐式调用其构造函数
	Test2 t2(12);//显式调用成功
}

struct  SPercon
{
	int Age;
	char *Name;
};

class CPerson
{
	int Age;
	char * Name;
};

class Base
{
public:
	virtual int   Fun()
	{
		return 0;
	}
};
class Derived : public Base
{
public:
	int  Fun() override
	{
		return 1;
	}
};


int main()
{
	Derived* p1 = new Derived;
	Base * p2 = p1;
	cout << p2->Fun() << endl;
	cout << (Base*)p2->Fun() << endl;
	
	auto func(int i)->int(*)[10];
	int odd[] = { 1,3,5,7,9 };
	int even[] = { 0,2,4,6,8 };
	//decltype(odd) *arrPtr(int i) { return (i % 2) ? &odd : &even; };

	autoDemo();
	getchar();

	return 0;
}