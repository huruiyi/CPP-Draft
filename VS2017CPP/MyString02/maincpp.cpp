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

//1.�� 32 λ������Ĭ�������, sizeof(a)���ڣ�  ���ֽڣ�
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
//��VC++���� 12. ������Ҫ������������
//һ���麯����vtable����ڱ��ַvpointer(��дvptr)
//�����ֽڶ���.
//���Ǿ�̬��Ա�����ж�����, ������sizeof�ռ�.
//�ڴ󲿷�C++��ʵ����, �����麯�������ǰ4��BYTE���麯��vtable����������ڵ�ַ.����sizeof����Ҫ�������4��byte�ĳ���, ������, ���sizoef()Ϊ�������ݳ�Ա�ܵ�sizeof֮��, ������int i, ��char c.����char c���ֽڶ���Ϊ4.�����ܳ���Ϊ
//Sizeof(a) = sizeof(vtable)+size(int) + sizeof(char + �ֽڶ���) = 12;

//2����AΪ�����࣬����������   ������ȷ�ġ�(2��)

//
//B��A *p;
//

//�����ʱ������ϣ�����������Ϊ���������һ���ӿڡ������˵������Ի��������������ת����ʹ�����Ľӿڣ�����ϣ���û�ʵ�ʵĴ���һ������Ķ���ͬʱ����һ�����麯������ӿ��з��ó�Աԭ����������һ��Ҫ�ṩһ�ο��ܶ����������������Ĵ��롣
//
//������㣬�����ڻ����м�������һ�����麯��(pure virtual function), ʹ�û����Ϊ������(abstract class).
//���麯��ʹ�ùؼ���virtual�������������� = 0�������ͼȥʵ����һ�������࣬�����������ֹ���ֲ�����
//���̳�һ���������ʱ�򣬱���ʵ�����еĴ��麯���������ɳ�������������Ҳ��һ�������ࡣ
//Virtual void fun() = 0; ���߱�������vtable��Ϊ��������һ��λ�ã���������ض�λ�ò��ŵ�ַ��
//
//���������ӿ�Ŀ����Ϊ�˽����๫���Ĳ����������������ͨ��һ�������ӿ�������һ���࣬����������ӿڲ���Ҫ����(���߲���Ҫ��ȫʵ��)�����Դ���һ��������.

//3.�ٶ�CSomething��һ���ִ࣬��������Щ���֮���ڴ��ﴴ���ˣ�   ����CSomething����
//
//CSomething a();// ֻ�Ǹ���������
//CSomething a;����һ����Ķ���
//CSomething b(2);// +1
//
//CSomething c[3];// +3����������
//
//CSomething &ra = b;// ���ã�û���¹���
//
//CSomething d = b;// +1�����ÿ������캯��
//
//CSomething *pA = c;// ֻ�Ǹ�ָ�븳ֵ
//
//CSomething *p = new CSomething(4);// +1�����첢��ָ�븳ֵ
//
//(2��)
//E��6

//4.��������º���ģ��Ķ��壺
//template <class T>
//T func(T x, T y)
//{
//	return x + y;
//}
//��Ժ���func���ò���ȷ���ǣ�   ����
//c.func(3, 2.5)
//����ģ�岻�����Զ�����ת���������ϸ�ƥ������
//��ͨ�������Խ����Զ�����ת��

//5.��֪����B���Ѿ�������--�� = �� + ��[]������������п϶����ڳ�Ա������������ǣ�  ����(2��)
//
//D��= ��[]
//= , [], () ��->������ֻ��ͨ����Ա������������

//6.���й�����ļ̳������У���  ���Ǵ���ġ�(2��)//�ο���ò���Ǵ��
//��������Է��ʻ�����������ݳ�Ա��Ҳ�ܵ��û�������г�Ա����

//������̳л��࣬������ӵ�л�����ȫ����Ա�����ͳ�Ա���������˹��������֮��ĳ�Ա���������������������У��̳еĳ�Ա����һ����ֱ�ӷ��ʣ���ͬ�ļ̳з�ʽ�ᵼ�²�ͬ�ķ���Ȩ�ޡ�

//7�������¶������䣺int w[2][3]����*pw��[3] �� pw=w �� ���w ����Ԫ�طǷ�������_____
//B. *(pw + 1)[2]

//*(w[0] + 2)
////ѡ��A��ʾԪ��w[0][2]
//
//*(pw + 1)[2]
//
//
//pw[0][0]
////ѡ��C��ʾԪ��w[0][0]
//
//*(pw[1] + 2)
//ѡ��D��ʾԪ��w[1][2]
//��ѡ��B��pw + 1��ʾ��2��Ԫ�صĵ�ַ��(pw + 1)[2]�൱��(pw + 1) + 2����ʾ��4��Ԫ�صĵ�ַ����Ȼ�����ö�ά����ķ�Χ��

//8��������У����������ڲ�ͬ��һ���ǣ�   ����(2��)
void test8()
{
	cout << "1. " << setfill(' ') << "Hello! " << endl;

	cout << "1. " << ' ' << "Hello! \n";//bѡ��

	cout << "1. Hello! " << endl;

	cout << "1. " << setw(7) << "Hello! ";
	cout << endl;
}

//9 .��һ����A�������ݳ�Ա���£�
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
//���캯���У���Ա����һ��Ҫͨ����ʼ���б�����ʼ�����ǣ�  ��
//B.  b c
//��ʼ����Ա�б�(�����б�)ֻ���ڹ��캯��ʹ�á�
//��C++ Primer������5�� P259�����ᵽ�����������������Ҫʹ�ó�ʼ����Ա�б�
//1��const������Ա����Ϊ����ֻ�ܳ�ʼ�������ܸ�ֵ�����Ա�����ڳ�ʼ���б��У�
//2���������͵ĳ�Ա�����ñ����ڶ����ʱ���ʼ�������Ҳ������¸�ֵ������ҲҪд�ڳ�ʼ���б��У�
//3����Ա������û��Ĭ�Ϲ��캯�����ࡣ��û���ṩ��ʾ��ʼ��ʽ�����������ʽʹ�ó�Ա���͵�Ĭ�Ϲ��캯��������û��Ĭ�Ϲ��캯���������������ʹ��Ĭ�Ϲ��캯������ʧ�ܡ�
//ע�⣺
//C++��ʼ�����Աʱ���ǰ���������˳���ʼ���ģ������ǰ��ճ����ڳ�ʼ���б��е�˳������Ҫ�ر�ע�⣬��֤����˳��һ�²���������֤��Ч�ʺ�׼ȷ�ԡ�

//10.double r = 99, *p = &r ;
//*p = r;
//��������ȷ��������_ ��
//D .���"*p=r;"ȡ����r ��ֵ�Ż�r ��
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

//11 . ��֪���º���, ���������Ľ����ȷ���� ��  ����

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
//C��constructor A constructor B

//12.���������������ǣ�  ����
void test12()
{
	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 };
	char *p;

	int i;

	i = 8;

	p = a + i;

	printf("%s\n", p - 3);
}

//13.�������¶���:

//struct snow
//{
//	int a;
//
//	float b;
//
//}c2, *p;
//����p = &c2; ���c2�еĳ�Աa����ȷ������:��  ��
//
//B.(*p).a
//. ��������ʽṹ����� ������ ��Ա.
//->��������ʽṹ����� ָ�� ������ ��Ա.

//14. ����������Ŀ���ǣ�  ����
//A �򻯳���
//B ����������
//C �������Ч��
//D ����Ŀ�����
//�������Ϊ��ǿ��"������͵�ĳЩ����û������, ֻ��Ϊ�˼̳�, ��Ҫ�����������͵Ķ���"

//15. ���� char **a[3][4], ��32λϵͳ�������ռ�е��ڴ�ռ�Ϊ��  ����(2��)

//C��48

//3*4*4=48

//16. ����ָ�������õ�����
//
//
//a)���ô�����ͬʱ�����ʼ���������ñ�������һ������Ķ���ָ�봴����ʱ����Բ��س�ʼ����
//
//b)�����ڿ����ã����Ǵ���NULLָ�롣
//
//c)�����ڳ�ʼ��֮�󣬲��ɸı�ı�Ϊ������������ָ����Ըı�ָ��
//
//d)���Բ��棬���õ��÷��Ͷ���һ�����ڶ����Ʋ��棬����һ�㶼��ͨ��ָ����ʵ�ֵġ�

//17������C++�ж�̬��ʵ�ֲ��衣(5��)
//
//a)������Ҫ���麯�����麯����
//
//b)������д�����е��麯����
//
//c)�����ָ�������ָ������Ķ��󣬲�ͨ�������ָ������õ����麯����

bool greaterThan5(int val)
{
	return val > 5;
}
//Ҫ��
//��1����ia���Ƶ�һ��vector����vec�к�һ��list������lst�С�
//��2����vec�����е�����ֵԪ��ɾ����
//��3��ʹ�������㷨(accumulate)����vec��������Ԫ�صĺ͡�
//��4��ʹ�������㷨(count_if)����lst�����д���5��Ԫ�صĸ�����
//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
void test17()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
	//(1)��ia���Ƶ�һ��vector����vec�к�һ��list������lst�С�
	vector<int> vec(ia, ia + sizeof(ia) / sizeof(int)); ////��v[begin(), end())�����е�Ԫ�ؿ���������
	list<int>lst(ia, ia + sizeof(ia) / sizeof(int));
	//�������鿴���ƽ��
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	//��������,�鿴���
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	cout << "================����==================" << endl;
	//��2����vec�����е�����ֵԪ��ɾ����
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it % 2 != 0)//��������ɾ����Ȼ������ͷ����
		{
			vec.erase(it);
			it = vec.begin();
		}
	}
	if (*(vec.begin()) % 2 != 0)//�ټ��һ���׸�Ԫ���Ƿ�Ϊ�������ǵĻ���ɾ��
	{
		vec.erase(vec.begin());
	}
	cout << endl;
	//���������ɾ�����
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//��3��ʹ�������㷨(accumulate)����vec��������Ԫ�صĺ͡�
	int sum = accumulate(vec.begin(), vec.end(), 0);// ��������Ԫ���ۼ��ܺ�(������ʼ������,��������������,�ۼ�ֵ)
	cout << "accumulate:" << sum << endl;

	//��4��ʹ�������㷨(count_if)����lst�����д���5��Ԫ�صĸ�����
	int n = count_if(lst.begin(), lst.end(), greaterThan5); //ͳ��Ԫ�س��ִ���(������ʼ������,��������������,ν��)
	cout << "����5��Ԫ�ظ���:" << n << endl;
}

void test18()
{
	//�вι���
	MyString str1("hello world.");
	//����<<
	cout << str1 << endl;

	//����>>
	cin >> str1;
	cout << str1 << endl;

	//��������
	MyString str2(str1);
	cout << str2 << endl;

	////��ֵ���������
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