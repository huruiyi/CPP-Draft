#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"MyString.h"
using namespace std;

MyString::MyString()
{
	this->pString = NULL;
	this->mSize = 0;
}

//初始化
MyString::MyString(const char *s)
{
	int len = strlen(s);
	this->pString = new char[len + 1];
	strcpy(this->pString, s);
	this->mSize = len;
}
MyString::MyString(int n, char  ch)
{
	int len = n;
	this->pString = new char[len + 1];
	memset(this->pString, 0, len + 1);
	for (int i = 0; i < len; i++)
	{
		this->pString[i] = ch;
	}
	this->mSize = len;
}
MyString::MyString(const MyString &str)
{
	int len = strlen(str.pString);
	this->pString = new char[len + 1];
	strcpy(this->pString, str.pString);
	this->mSize = len;
}

//赋值重载
MyString & MyString::  operator=(const MyString &str)
{
	if (this->pString)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	int len = strlen(str.pString);
	this->pString = new char[len + 1];
	strcpy(this->pString, str.pString);
	this->mSize = len;

	return *this;
}

//取值重载
char & MyString::  operator[](int index)
{
	return this->pString[index];
}

//相加操作，返回的是新值 。如果为空返回自身
MyString  MyString::  operator+(const MyString &str)
{
	//if (NULL == str.pString)
	//{
	//    return *this;
	//}
	//int len = this->mSize + str.mSize;
	//
	//MyString newStr;
	//newStr.pString = new char[len + 1];
	//strcat(newStr.pString, this->pString);
	//strcat(newStr.pString, str.pString);
	//newStr.mSize = len;
	//return newStr;
	//

	if (NULL == str.pString)
	{
		return *this;
	}
	int len = this->mSize + str.mSize;
	char *newP = new char[len + 1];
	memset(newP, 0, len + 1);
	MyString newStr;

	strcat(newP, this->pString);
	strcat(newP, str.pString);

	newStr.pString = newP;
	newStr.mSize = len;
	return newStr;
}
MyString  MyString::  operator+(const char  *c)
{
	if (NULL == c)
	{
		return *this;
	}
	int len = this->mSize + strlen(c);

	MyString newStr;
	newStr.pString = new char[len + 1];
	memset(newStr.pString, 0, len + 1);

	strcat(newStr.pString, this->pString);
	strcat(newStr.pString, c);
	newStr.mSize = len;
	return newStr;
}

//追加操作，返回的是自身，先前的地址，值要处理
MyString & MyString::  operator+=(const MyString &str)
{
	if (NULL == str.pString)
	{
		return *this;
	}

	int len = this->mSize + str.mSize;
	char *newP = new char[len + 1];;
	memset(newP, 0, len + 1);

	strcat(newP, this->pString);
	strcat(newP, str.pString);
	//扩充空间，先前的先处理掉
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = newP;
	this->mSize = len;
	return *this;
}
MyString & MyString::  operator+=(const char *c)
{
	if (NULL == c)
	{
		return *this;
	}

	int len = this->mSize + strlen(c);
	char *newP = new char[len + 1];;
	memset(newP, 0, len + 1);

	strcat(newP, this->pString);
	strcat(newP, c);
	//扩充空间，先前的先处理掉
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = newP;
	this->mSize = len;
	return *this;
}

//判断
bool  MyString::  operator==(const MyString &str)
{
	//str==NULL ||
	if (NULL == str.pString || mSize != str.mSize)
	{
		return false;
	}
	return !strcmp(this->pString, str.pString);
}
bool  MyString::  operator==(const char *s)
{
	if (NULL == s || mSize != strlen(s))
	{
		return false;
	}
	return !strcmp(this->pString, s);
}

//获取字符大小
int  MyString::size()
{
	return this->mSize;
}

//MyString->const char *
const char *  MyString::c_str()
{
	return this->pString;
}

void MyString::ShowInfo()
{
	cout << "[" << this->pString << "]" << "   " << this->mSize << endl;
}

MyString::  ~MyString()
{
	if (this->pString)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
}

//输出
std::ostream & operator<<(std::ostream &out, const MyString &str)
{
	out << str.pString;
	return out;
}
//输入
std::istream & operator>>(std::istream &in, MyString &str)
{
	char    ch[1024] = { 0 };
	in.getline(ch, 1024);

	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
		str.mSize = 0;
	}
	int  len = strlen(ch);
	str.pString = new char[len + 1];
	strcpy(str.pString, ch);
	str.mSize = len;

	return in;
}