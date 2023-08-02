#include <iostream>
#include<string>
//不能给右值赋值
//左值引用可以被赋值

//总而言之，左值是具有某种存储支持的变量，右值是临时值
int& GetValue()
{
    int value = 10;
	return value;
}

void SetValue(int v)
{

}

void PrintName(std::string& name)//非常量的左值引用
{
	
}

void PrintName2(std::string&& name)//右值引用，仅仅接受临时值
{

}
int main()
{
	GetValue() = 5;
	
	//函数被调用时，右值会用来被创建一个左值
	//右值不能赋给左值引用，非const引用必须为左值
	int i = 10;
	SetValue(i);
	SetValue(10);
	

	std::string Firstname = "Zhanwei";
	std::string Lastname = "Chen";
	std::string Fullname = Firstname + Lastname;//左边都是左值，右边都是右值
	PrintName(Firstname);
	PrintName(Lastname);//调用PrinName2时报错，无法将右值引用绑定到左值
	PrintName2(Firstname + Lastname);//当PrintName参数不为const&时，该表达式报错
	std::cin.get();	
}




