#pragma once
#include<iostream>
using namespace std;
class MyString
{
public:
	MyString(const char* str = "");  //��ͨ���캯��
	MyString(const MyString  & other);    //�������캯��
	MyString& operator=(const MyString& other);    //��ֵ���������
	MyString& operator=(const char* str);    //��ֵ���������
	~MyString();    //��������
	char& operator[](unsigned int index);
	friend ostream& operator<<(ostream& os, const MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
private:
	char* m_str;
};