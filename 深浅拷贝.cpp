浅拷贝：简单的值传递拷贝操作，可能出现堆区内存重复释放，利用深拷贝解决：
	person(const person& p)
	{
		cout << "person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//深拷贝操作
		m_height = new int(*p.m_height);

	}

	

深拷贝：在堆区重新申请空间进行拷贝操作
在析构函数代码处释放堆区申请的内存：
	~person()
	{
		if (m_height != NULL)
		{
			delete m_height;
		}
		cout << "析构函数调用" << endl;
	}
