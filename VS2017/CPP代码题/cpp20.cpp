#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;
#include "MyString.h"

int main20()
{
	/*
MyString(const char* str = "");  //��ͨ���캯��
MyString(const MyString  & other);    //�������캯��
MyString& operator=(const MyString& other);    //��ֵ���������
MyString& operator=(const char* str);    //��ֵ���������
~MyString();    //��������
char& operator[](unsigned int index);
friend ostream& operator<<(ostream& os, const MyString& str);
friend istream& operator>>(istream& is, MyString& str);*/

	MyString ms1("Hello");
	MyString ms2(ms1);
	MyString ms3 = ms1;
	MyString ms4 = "World";
	cout << ms4[0] << endl;
	cout << ms4 << endl;

	MyString ms5;
	cin >> ms5;
	cout << ms5 << endl;
	system("pause");
	return 0;
}