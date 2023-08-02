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
	
	//第三种种创建文件方法
	//std::ofstream FileOutput1;
	//FileOutput1.open("C:\\Users\\26986\\Desktop\\Text1.txt");//打开文件，不存在则创建，存在则截断内容
	
	//创建文件附加参数
	//ios::out		缺省值，截断文件内容							---->		std::ofstream FileOutput(filename,std::ios::out)	
	//ios::trunc	截断文件内容									---->		std::ofstream FileOutput(filename,std::ios::trunc)
	//ios::app		不截断文件内容，只在文件末尾追加文件			----->		std::ofstream FileOutput(filename,std::ios::app)
	
	if (FileOutput.is_open() == true)
	{
		//向文件中写入内容
		FileOutput << "卢本伟牛逼" << std::endl;
		FileOutput << "Elden Ring" << std::endl;
		FileOutput << "Sekiro:Shadows Die Twice" << std::endl;

		FileOutput.close();//关闭文件，FileOutput对象失效前自动调用close()
	std::cout << "Open File Accomplished!" << std::endl;
	}
	else//失败1)目录不存在 2)磁盘空间已满 3)没有权限，常见于Linux
	{
		std::cout << "Open File Failed..." << std::endl;
	}
	

	std::cin.get();
}