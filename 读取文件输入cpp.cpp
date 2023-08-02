#include<iostream>
#include<string>
#include<fstream>


int main()
{	
	//第一种创建文件方法
	//std::ofstream FileOutput("C:\\Users\\26986\\Desktop\\Text.txt");//第一种创建文件方法
	
	//第二种创建文件方法
	std::string filename = R"(C:\\Users\\26986\\Desktop\\Text.txt)";
	std::ofstream FileOutput(filename,std::ios::app);
	std::ifstream FileInput(filename);
	//第三种种创建文件方法
	//std::ofstream FileOutput1;
	//FileOutput1.open("C:\\Users\\26986\\Desktop\\Text1.txt");//打开文件，不存在则创建，存在则截断内容
	
	//创建文件附加参数
	//ios::in	---->std::ifstream FileInput(filename,std::ios::in)	

	
	if (FileInput.is_open() == true)
	{
		//打开文件方法1，std::getline()
		std::string Buffer;
		while (std::getline(FileInput, Buffer))
		{
			std::cout << Buffer << std::endl;
		}
		//方法2，std::cin
		while (FileInput >> Buffer)
		{
			std::cout << Buffer << std::endl;
		}

		FileInput.close();
		std::cout << "------------" << std::endl << "Open File Accomplished!" << std::endl;
	}
	else//失败1)目录不存在 2)没有权限，常见于Linux
	{
		std::cout << "Open File Failed..." << std::endl;
	}
	

	std::cin.get();
}