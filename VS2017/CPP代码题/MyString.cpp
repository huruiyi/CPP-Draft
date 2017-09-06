#define  _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char* str) //普通构造函数
{
	this->m_str = new char[strlen(str) + 1];
	strcpy(this->m_str, str);
}
MyString::MyString(const MyString  & other)    //拷贝构造函数
{
	this->m_str = new char[strlen(other.m_str) + 1];
	strcpy(this->m_str, other.m_str);
}
MyString& MyString::operator=(const MyString& other)   //赋值运算符重载
{
	if (this->m_str != NULL)
	{
		delete[] this->m_str;
		this->m_str = NULL;
	}

	this->m_str = new char[strlen(other.m_str) + 1];
	strcpy(this->m_str, other.m_str);

	return *this;
}
MyString& MyString::operator=(const char* str)   //赋值运算符重载
{
	if (this->m_str != NULL)
	{
		delete[] this->m_str;
		this->m_str = NULL;
	}

	this->m_str = new char[strlen(str) + 1];
	strcpy(this->m_str, str);

	return *this;
}
MyString::~MyString()  //析构函数
{
	if (this->m_str != NULL)
	{
		delete[] this->m_str;
		this->m_str = NULL;
	}
}
char& MyString::operator[](unsigned int index)
{
	return this->m_str[index];
}
ostream& operator<< (ostream& os, const MyString& str)
{
	os << str.m_str;
	return os;
}
istream& operator>>(istream& is, MyString& str)
{
	char buf[1024] = { 0 };
	is.getline(buf, 1024);

	if (str.m_str != NULL)
	{
		delete[] str.m_str;
		str.m_str = NULL;
	}

	str.m_str = new char[strlen(buf) + 1];
	strcpy(str.m_str, buf);

	return is;
}