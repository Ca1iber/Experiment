#include<string>
#include <iostream>
#include <memory>
#include <vector>

template<typename t>
void print(t value)
{
	using namespace std;
	cout << value << endl;
}

template<typename T,int Typename>
class Array
{
public:
	T m_Array[Typename];
public:
	int GetSize() const
	{
		return Typename;
	}
};

int main()
{
	Array<std::string, 5> arr;
	for (int i = 0; i < arr.GetSize(); i++)
	{
		std::cin >> arr.m_Array[i];
	}
	std::cout << arr.GetSize()	 << std::endl;
	for (int i = 0; i < arr.GetSize(); i++)
	{
		std::cout << arr.m_Array[i] << std::endl;	
	}
	std::cout << '!' << std::endl;
}

	