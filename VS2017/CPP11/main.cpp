#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

const int func_cint(void);
struct Foo { int x; };
void test1()
{
	decltype(func_cint()) fm = 0;
	const Foo foo = Foo();
	decltype(foo.x) a = 0;
	decltype((foo.x)) b = a; // 特别注意和上面的比较

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

class Foot
{
public:
	Foot(std::initializer_list<int>)
	{
	}
};

void test3()
{
	Foot fool{ 1, 2, 3, 4 };
}

void test4()
{
	int fibarray[] = { 0, 1, 1, 2, 3, 5, 8, 13 };
	for (auto v : fibarray) {
		std::cout << v << std::endl;
	}
}

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
	return t + u;
}

int& foo(int& i);
float foo(float& f);

template <typename T>
auto add(T &val) -> decltype(foo(val))
{
	return foo(val);
}

int sum(const std::initializer_list<int>& list) {
	int total = 0;
	for (auto& e : list) {
		total += e;
	}

	return total;
}

void test5()
{
	auto list = { 1, 2, 3,4,5 };

	int a = sum(list);
	cout << a << endl;

	int b = sum({ 1, 2, 3,4 });
	cout << b << endl;

	int c = sum({});
	cout << c << endl;
}
int main()
{
	test5();

	getchar();
	return 0;
}