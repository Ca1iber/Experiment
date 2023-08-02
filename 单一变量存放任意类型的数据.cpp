#include<iostream>
#include<string>
#include<variant>

class a
{
public:
	int m_a;
};

int main()
{
	std::variant<std::string, int> data;
	data = "fake";
	data = 132;
	data.index();
	std::cin.get();
}