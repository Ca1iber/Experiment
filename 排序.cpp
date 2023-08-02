#include<string>
#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>
int main()
{
	std::vector<int> Vec;
	for (int i = 0; i < 10; i++)
	{
		int a;
		std::cin >> a;
		Vec.push_back(a);
	}
	std::sort(Vec.begin(), Vec.end());
	for (auto v : Vec )
	{
		std::cout << v << std::endl; 
	}

	std::cin.get();
}

	