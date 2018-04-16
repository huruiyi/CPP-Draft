#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include "MyString.h"
using namespace std;

void MyStringTest()
{
	/*
	1：初始化
	MyString(const char *s);
	MyString(int n, char  ch);
	MyString(const MyString &str);
	*/
	MyString s1 = "ABCDEFG";
	s1.ShowInfo();

	MyString s2(5, 'B');
	s2.ShowInfo();

	MyString s3(s1);
	s3.ShowInfo();

	/************************************************************************/
	/*  赋值重载    MyString &operator=(const MyString &str);            */
	/************************************************************************/
	MyString s4 = s2;
	s4.ShowInfo();

	/************************************************************************/
	/*    取值重载  char &operator[](int index);                                      */
	/************************************************************************/
	MyString s5("123456789");
	cout << s5[2] << endl;

	/************************************************************************/
	/*         相加操作，返回的是新值
	*         MyString operator+(const MyString &str);
	*         MyString operator+(const char  *c);                                    */
	/************************************************************************/

	MyString s6("123456");
	MyString s7("abcdef");

	MyString s8 = s6 + s7;
	MyString s9 = s6 + "54321";
	s6.ShowInfo();
	s7.ShowInfo();
	s8.ShowInfo();
	s9.ShowInfo();

	/************************************************************************/
	/*  追加操作，返回的是自身，先前的只地址，值要处理
	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *c);                               */
	/************************************************************************/

	cout << "/************************************************************************/" << endl;
	MyString s10("123456");
	MyString s11("789");
	s10.ShowInfo();
	s11.ShowInfo();
	s10 += s11;
	s10.ShowInfo();
	s11.ShowInfo();

	cout << "/************************************************************************/" << endl;
	MyString s12("123");
	s12.ShowInfo();
	s12 += "456";
	s12.ShowInfo();

	/************************************************************************/
	/*  判断
	bool operator==(const MyString &str);
	bool operator==(const char *s);                                         */
	/************************************************************************/

	MyString s13 = "abc";
	MyString s14 = "abc";
	MyString s15 = "def";
	cout << (s13 == s14 ? "相等" : "不相等") << endl;
	cout << (s13 == s15 ? "相等" : "不相等") << endl;
	const char *ch1 = "abc";
	const char *ch2 = "def";
	cout << (s13 == ch1 ? "相等" : "不相等") << endl;
	cout << (s13 == ch2 ? "相等" : "不相等") << endl;

	/************************************************************************/
	/*  //获取字符大小
	int size();
	//  MyString->const char *
	const char * c_str();                                                          */
	/************************************************************************/
	MyString s16 = "abcdef";
	cout << s16.c_str() << endl;

	/************************************************************************/
	/* >>输入                                                                     */
	/************************************************************************/
	MyString s18 = "123";
	cin >> s18;
	s18.ShowInfo();
}

int main()
{
	MyStringTest();
	system("pause");
	return 0;
}