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

//�Ϸ��㽶
class SouthBanana :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthBanana.." << endl;
	}
};

//�����㽶
class NorthBanana :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "NorthBanana.." << endl;
	}
};

//�Ϸ�ƻ��
class SouthApple :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthApple.." << endl;
	}
};

//����ƻ��
class NorthApple :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "NorthApple.." << endl;
	}
};

//�Ϸ�ľ��
class SouthMg :public Fruit
{
protected:
	void virtual sayName()
	{
		cout << "SouthMg.." << endl;
	}
};

//����ľ��
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