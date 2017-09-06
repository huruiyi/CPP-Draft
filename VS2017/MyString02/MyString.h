#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:
	friend ostream& operator<<(ostream &out, const MyString &str);
	friend istream& operator>>(istream &in, MyString &str);
public:
	MyString();
	MyString(const char *str);
	MyString(const MyString &str);
	~MyString();

	//∏≥÷µ‘ÀÀ„∑˚÷ÿ‘ÿ
	MyString& operator=(const MyString &str);
	MyString& operator=(const char* str);
	//[]
	char& operator[](int pos);
	//+
	MyString operator+(const MyString &str);
	MyString operator+(const char* str);
	//==
	bool operator==(const MyString &str);
	//!=
	bool operator!=(const MyString &str);
	//
	void show();
private:
	char *m_str;
	int m_size;
	int m_capacity;
};