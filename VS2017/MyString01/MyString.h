#ifndef _MyString_H
#define   _MyString_H
#include<iostream>

class MyString
{
	friend	std::ostream & operator<<(std::ostream &out, const MyString &str);
	friend	std::istream & operator>>(std::istream &in, MyString &str);
public:
	MyString();

	//��ʼ��
	MyString(const char *s);
	MyString(int n, char  ch);
	MyString(const MyString &str);

	//��ֵ����
	MyString &operator=(const MyString &str);

	//ȡֵ����
	char &operator[](int index);

	//��Ӳ��������ص�����ֵ
	MyString operator+(const MyString &str);
	MyString operator+(const char  *c);

	//׷�Ӳ��������ص���������ǰ��ֻ��ַ��ֵҪ����
	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *c);

	//�ж�
	bool operator==(const MyString &str);
	bool operator==(const char *s);

	//��ȡ�ַ���С
	int size();

	//MyString->const char *
	const char * c_str();

	void ShowInfo();

	~MyString();
public:
	char *pString;
	int mSize;
};

#endif // !_MyString_H
