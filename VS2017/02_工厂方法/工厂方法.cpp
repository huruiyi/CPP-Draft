#include<iostream>
#include<string>

using namespace std;

class Fruit
{
public:
	virtual Fruit *  sayName() = 0;
};

class FruitFactory
{
public:
	virtual Fruit *getFruit()
	{
		return NULL;
	}
};

class  Banana :public Fruit
{
protected:
	virtual Fruit *  sayName()
	{
		cout << "Banana ......" << endl;
		return NULL;
	}
};

class  Pear :public Fruit
{
protected:
	virtual Fruit* sayName()
	{
		cout << "Pear ......" << endl;
		return NULL;
	}
};

class BananaFactory :public FruitFactory
{
public:
	virtual Fruit * getFruit()
	{
		return new Banana();
	}
};

class PearFactory :public FruitFactory
{
public:
	virtual Fruit * getFruit()
	{
		return new Pear();
	}
};
int main()
{
	FruitFactory *ff = NULL;
	Fruit *fruit = NULL;

	ff = new BananaFactory();
	fruit = ff->getFruit();
	fruit->sayName();
	delete fruit;
	delete ff;

	ff = new PearFactory();
	fruit = ff->getFruit();
	fruit->sayName();
	delete fruit;
	delete ff;

	getchar();
	return 0;
}