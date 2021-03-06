#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
	void a()
	{
		cout << "v  ";
	}
	void c()
	{
		cout << "c  ";
	}
	void e()
	{
		cout << "z  ";
	}
	// 2. Steps requiring peculiar implementations are "placeholders" in base class
	virtual void ph1() = 0;
	virtual void ph2() = 0;
public:
	// 1. Standardize the skeleton of an algorithm in a base class "template method"
	void execute()
	{
		a();
		ph1();
		c();
		ph2();
		e();
	}
};

class One : public Base
{
	// 3. Derived classes implement placeholder methods
	/*virtual*/void ph1()
	{
		cout << "4  ";
	}
	/*virtual*/void ph2()
	{
		cout << "6  ";
	}
};

class Two : public Base
{
	/*virtual*/void ph1()
	{
		cout << "12  ";
	}
	/*virtual*/void ph2()
	{
		cout << "45  ";
	}
};

int main()
{
	Base *array[] =
	{
		&One(), &Two()
	};
	for (int i = 0; i < 2; i++)
	{
		array[i]->execute();
		cout << '\n';
	}
}
