#include<string>
#include <iostream>
#include <chrono>
#include <vector>
#include<array>
#include<thread>
static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;
	while (!s_Finished)
	{
		std::cout << "Working..." << std::endl;
		std::this_thread::sleep_for(1.5s);//用于给当前线程下达命令
	}
}

int main()
{
	std::thread worker(DoWork);
	std::cin.get();
	s_Finished = true;
	worker.join();
	std::cout << "Finished!" << std::endl;
	std::cin.get();
}

