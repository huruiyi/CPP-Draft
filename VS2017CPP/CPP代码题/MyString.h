#pragma once
#include<iostream>
using namespace std;
class MyString
{
public:
	MyString(const char* str = "");  //普通构造函数
	MyString(const MyString  & other);    //拷贝构造函数
	MyString& operator=(const MyString& other);    //赋值运算符重载
	MyString& operator=(const char* str);    //赋值运算符重载
	~MyString();    //析构函数
	char& operator[](unsigned int index);
	friend ostream& operator<<(ostream& os, const MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
private:
	char* m_str;
};