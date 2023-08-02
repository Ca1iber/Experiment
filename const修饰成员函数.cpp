常函数
·成员函数后加const后称之为常函数，修饰的是this的指向，让指针所指的值也不可以修改
·常函数不可以修改成员属性
·成员属性声明时加关键词mutable后在常函数中依然可以修改

常对象
·声明对象前加const称之为常对象
·常对象只能调用常函数


class person
{
public:
	void showperson() const
	{
		m_a=100;
	}
	mutable int m_a;
	int m_b;
};
void test()
{
	const person p;
	p.m_a = 100;
	//p.m_b=100;
	p.showperson();
}
