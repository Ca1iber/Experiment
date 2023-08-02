#include<string>
#include <iostream>
#include <memory>
#include <vector>
#include<array>

void PrintValue(int value)
{
	std::cout << value << std::endl;
}

void ForEach(const std::vector<int>& v,void(*Func)(int))
{
	for (auto a : v){
		Func(a);
	}
}

int main()
{
	std::vector<int> Vec({ 1,2,3,4,5 });
	ForEach(Vec, PrintValue);
	std::cin.get();
}

	