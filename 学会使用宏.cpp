#include<string>
#include <iostream>
#include <memory>
#include <vector>


#define LOG(x) std::cout<<x<<std::endl
#define DEBUG 1

#if DEBUG==1
#define TST(x)   std::cout<<x<<std::endl
#else
#define TST(x)
#endif


int main()
{
	LOG(3);
	std::cin.get();
}

	