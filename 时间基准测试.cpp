#include <iostream>
#include<vector>
#include<memory>
#include<chrono>

class Timer
{
public:
	Timer()
	{
		std::chrono::high_resolution_clock::now();//得到当前时间
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto EndTimepoint = std::chrono::high_resolution_clock::now();//得到当前时间

		auto Start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimepoint).time_since_epoch().count();
		auto duration = stop - Start;
		double ms = duration * 0.001;
		std::cout << ms << "ms" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;//将当前时间记录到一个私有变量中

};

int main()
{
	int a = 0;
	{
		Timer t;
		for (int i = 0; i < 1000000; i++)
		{
			a += 2;
		}
	}
	std::cout << a << std::endl;

	std::cin.get();
}

