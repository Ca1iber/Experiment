#include<iostream>
#include<string>
#include<fstream>


int main()
{
	std::ofstream FileOutput;
	
	FileOutput.open("Text.txt");//打开文件，不存在则创建，存在则截断内容

	//向文件中写入内容
	FileOutput << "卢本伟牛逼" << std::endl;
	FileOutput << "Elden Ring" << std::endl;
	FileOutput << "Sekiro:Shadows Die Twice" << std::endl;

	FileOutput.close();//关闭文件，FileOutput对象失效前自动调用close()

	std::cout << "Acomplished!" << std::endl;
	std::cin.get();
}