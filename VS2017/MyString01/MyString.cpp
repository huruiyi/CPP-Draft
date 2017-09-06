#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"MyString.h"
using namespace std;

MyString::MyString()
{
	this->pString = NULL;
	this->mSize = 0;
}

//��ʼ��
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

//��ֵ����
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

//ȡֵ����
char & MyString::  operator[](int index)
{
	return this->pString[index];
}

//��Ӳ��������ص�����ֵ �����Ϊ�շ�������
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

//׷�Ӳ��������ص���������ǰ�ĵ�ַ��ֵҪ����
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
	//����ռ䣬��ǰ���ȴ����
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
	//����ռ䣬��ǰ���ȴ����
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = newP;
	this->mSize = len;
	return *this;
}

//�ж�
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

//��ȡ�ַ���С
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

//���
std::ostream & operator<<(std::ostream &out, const MyString &str)
{
	out << str.pString;
	return out;
}
//����
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