#include<iostream>

using namespace std;

class Fruit
{
public:

	void virtual sayName()
	{
		cout << "Fruit.." << endl;
	}
protected:
	Fruit() {};
};

class FruitFactory
{
public:
	virtual Fruit * getFruitBanana()
	{
		cout << "FruitFactory:getFruitBanana" << endl;
		return NULL;
	}

	virtual Fruit * getApple()
	{
		cout << "FruitFactory:getApple" << endl;
		return NULL;
	}

	virtual Fruit * getMg()
	{
		cout << "FruitFactory:getMg" << endl;
		return NULL;
	}
};

//南方香蕉
class SouthBanana :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthBanana.." << endl;
	}
};

//北方香蕉
class NorthBanana :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "NorthBanana.." << endl;
	}
};

//南方苹果
class SouthApple :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthApple.." << endl;
	}
};

//北方苹果
class NorthApple :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "NorthApple.." << endl;
	}
};

//南方木瓜
class SouthMg :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthMg.." << endl;
	}
};

//北方木瓜
class NorthMg :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "NorthMg.." << endl;
	}
};

class NorthFactory :public FruitFactory
{
protected:
	virtual Fruit * getFruitBanana()
	{
		return  new NorthBanana();
	}

	virtual Fruit * getApple()
	{
		return  new NorthApple();
	}

	virtual Fruit * getMg()
	{
		return  new NorthMg();
	}
};

class SouthFactory :public FruitFactory
{
protected:
	virtual Fruit * getFruitBanana()
	{
		return  new SouthBanana();
	}

	virtual Fruit * getApple()
	{
		return  new SouthApple();
	}

	virtual Fruit * getMg()
	{
		return  new SouthMg();
	}
};

int main()
{
	FruitFactory * ff = NULL;
	Fruit * fruit1 = NULL;
	Fruit * fruit3 = NULL;
	Fruit * fruit2 = NULL;

	ff = new SouthFactory();
	fruit1 = ff->getApple();
	fruit1->sayName();
	fruit2 = ff->getFruitBanana();
	fruit2->sayName();
	fruit3 = ff->getMg();
	fruit3->sayName();

	ff = new NorthFactory();
	fruit1 = ff->getApple();
	fruit1->sayName();
	fruit2 = ff->getFruitBanana();
	fruit2->sayName();
	fruit3 = ff->getMg();
	fruit3->sayName();

	getchar();
	return  0;
}