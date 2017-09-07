#ifndef _MyString_H
#define   _MyString_H
#include<iostream>

class MyString
{
	friend	std::ostream & operator<<(std::ostream &out, const MyString &str);
	friend	std::istream & operator>>(std::istream &in, MyString &str);
public:
	MyString();

	//初始化
	MyString(const char *s);
	MyString(int n, char  ch);
	MyString(const MyString &str);

	//赋值重载
	MyString &operator=(const MyString &str);

	//取值重载
	char &operator[](int index);

	//相加操作，返回的是新值
	MyString operator+(const MyString &str);
	MyString operator+(const char  *c);

	//追加操作，返回的是自身，先前的只地址，值要处理
	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *c);

	//判断
	bool operator==(const MyString &str);
	bool operator==(const char *s);

	//获取字符大小
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
