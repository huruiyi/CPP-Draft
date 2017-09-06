#include<iostream>

using namespace std;

class Fruit
{
public:
	virtual void getFruit() {
		cout << "Fruit:getFruit" << endl;
	}
};

class Pear :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "Pear:getFruit" << endl;
	}
};

class Banana :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "Banana:getFruit" << endl;
	}
};

class Factory
{
	;
public:
	Fruit * Creat(char * name)
	{
		if (strcmp(name, "Pear") == 0)
		{
			return new Pear();
		}

		else if (strcmp(name, "Banana") == 0)
		{
			return new Banana();
		}
		else
		{
			return NULL;
		}
	}
};

//开闭原则不符合，，
int main()
{
	Factory *ff = NULL;
	Fruit * fruit = NULL;

	//继承，虚函数重写，基类指针指向子类对象
	ff = new Factory();
	fruit = ff->Creat("Pear");
	fruit->getFruit();
	delete fruit;
	delete ff;

	ff = new Factory();
	fruit = ff->Creat("Banana");
	fruit->getFruit();
	delete fruit;
	delete ff;

	getchar();
	return 0;
}