#include<iostream>
#include<string>

using namespace std;

class BookStore
{
public:
	virtual void SaleBook()
	{
		cout << "BookStore.SaleBook" << endl;
	}
};

class RealBookStore :public BookStore
{
public:
	virtual void SaleBook()
	{
		cout << "RealBookStore.SaleBook" << endl;
	}
};

class DDProxy :public BookStore
{
public:
	virtual void SaleBook()
	{
		RealBookStore realstore;
		douleEleven();
		douleEleven();
		realstore.SaleBook();
		douleEleven();
		douleEleven();

		cout << "DDProxy.SaleBook" << endl;
	}
	void douleEleven()
	{
		cout << "双十一打折促销半价" << endl;
	}
};

class Per
{
public:
	int Age;
	Per(){}
	~Per()
	{
		cout << "结束" << endl;
	}
};
int main()
{
	Per *p = new Per;
	delete p;
	p->Age = 12;
	DDProxy *ddproxy = new DDProxy();
	ddproxy->SaleBook();

	getchar();

	return 0;
}