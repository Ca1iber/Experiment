#include <iostream>
#include<vector>

class Base
{
public:
	Base()
	{
		std::cout << "Base Constructed！" << std::endl;
	}
	virtual ~Base()//告诉编译器该类有可能被拓展为子类，可能还有一个析构函数需要被调用
	{
		std::cout << "Base Destroyed！" << std::endl;
	}
};

class Derive : public Base
{
public:
	Derive()
	{
		std::cout << "Derive Constructed！" << std::endl;
	}
	~Derive()
	{
		std::cout << "Derive Destroyed！" << std::endl;
	}
};

int main()
{
	Base* MyBase = new Base();//使用默认构造
	delete MyBase;
	std::cout << "-----------------------" << std::endl;
	Derive* MyDerive = new Derive();//使用默认构造
	delete MyDerive;
	std::cout << "-----------------------" << std::endl;
	Base* Poly = new Derive();
	delete Poly;
	std::cin.get();
}

	