#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MyString.h"
using namespace std;

//默认构造
MyString::MyString()
{
	m_str = new char[10];
	memset(m_str, 0, 10);
	m_size = 0;
	m_capacity = 10;
}
//有参构造
MyString::MyString(const char *str)
{
	m_size = strlen(str);
	m_str = new char[m_size + 1];
	strcpy(m_str, str);
	m_capacity = m_size;
}
//拷贝构造
MyString::MyString(const MyString &str)
{
	this->m_size = str.m_size;
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str.m_str);
	m_capacity = m_size;
}
//析构函数
MyString::~MyString()
{
	if (NULL != m_str)
	{
		delete[]m_str;
		m_str = NULL;
	}
}
//<<
ostream& operator<<(ostream &out, const MyString &str)
{
	out << str.m_str;
	return out;
}
//>>
istream& operator>>(istream &in, MyString &str)
{
	char temp[1024];
	in >> temp;
	if (NULL != str.m_str)
	{
		delete[]str.m_str;
	}
	str.m_size = strlen(temp);
	str.m_str = new char[str.m_size + 1];
	strcpy(str.m_str, temp);
	return in;
}
//=赋值运算符重载
MyString& MyString::operator=(const MyString &str)
{
	if (NULL != this->m_str)
	{
		delete[]m_str;
	}
	this->m_size = str.m_size;
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str.m_str);

	m_capacity = m_size;
	return *this;
}
MyString& MyString::operator=(const char* str)
{
	if (NULL != this->m_str)
	{
		delete[]m_str;
	}
	this->m_size = strlen(str);
	this->m_str = new char[this->m_size + 1];
	strcpy(this->m_str, str);

	m_capacity = m_size;
	return *this;
}
//[]
char& MyString::operator[](int pos)
{
	return this->m_str[pos];
}
//+
MyString MyString::operator+(const MyString &str)
{
	int newSize = this->m_size + str.m_size;
	char *temp = new char[newSize + 1];
	memset(temp, 0, newSize + 1);
	if (NULL != this->m_str)
		strcat(temp, this->m_str);
	strcat(temp, str.m_str);
	MyString newStr(temp);

	m_capacity = m_size;
	return newStr;
}
MyString MyString::operator+(const char* str)
{
	int newSize = this->m_size + strlen(str);
	char *temp = new char[newSize + 1];
	memset(temp, 0, newSize + 1);
	if (NULL != this->m_str)
		strcat(temp, this->m_str);
	strcat(temp, str);
	MyString newStr(temp);

	m_capacity = m_size;
	return newStr;
}
//==
bool MyString::operator==(const MyString &str)
{
	if (0 == strcmp(this->m_str, str.m_str))
		return true;
	else
		return false;
}
//!=
bool MyString::operator!=(const MyString &str)
{
	if (0 != strcmp(this->m_str, str.m_str))
		return true;
	else
		return false;
}
//
void MyString::show()
{
	cout << "this is MyString." << endl;
}