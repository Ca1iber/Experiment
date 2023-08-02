·代码区：存放函数体的二进制代码，由操作系统进行管理
·全局区：存放全局变量和静态变量以及常量
·栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
·堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

程序运行前：
.exe文件未执行前分为两个区：
·代码区：存放CPU执行的机器指令
	代码区共享，让同一个程序执行多次时不需要拷贝多份相同代码
	代码区只读，防止程序意外篡改代码

·全局区：数据在程序结束后由操作系统释放
	包含全局变量，静态变量以及常量

·栈区：由编译器自动分配释放，存放函数的参数，局部变量等，不要返回局部变量的地址

·堆区：主要利用new在堆区开辟内存，释放内存用delete操作符
	new返回的是该数据类型的指针： int *p=new int(10);
			                 int* arr=new int[10]创建有10个空间的数组
	delete p;//释放变量		delete[] arr;//释放数组
