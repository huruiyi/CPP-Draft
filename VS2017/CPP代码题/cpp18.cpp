#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal();
	virtual void voice() = 0;
};
Animal::Animal()
{
}
class Cat :public Animal
{
public:
	Cat() {};
	virtual void voice()
	{
		cout << "Cat voice()" << endl;
	}
};

class Dog :public Animal
{
public:
	Dog() {};
	virtual void voice()
	{
		cout << "Dog voice()" << endl;
	}
};

int main18()
{
	Animal * animal1 = new Dog;
	animal1->voice();
	Animal * animal2 = new Cat;
	animal2->voice();

	system("pause");
	return 0;
}