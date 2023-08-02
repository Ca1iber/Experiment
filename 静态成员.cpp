静态成员就是在成员变量和成员函数前加上关键字static，称之为静态成员
静态成员分为：

·静态成员变量
	1.所有对象共享同一份数据
	2.在编译阶段分配内存
	3.类内声明，类外初始化

class person
{
public:

	static int m_a;
};
int person::m_a = 100;
void test()
{
	person p1;
	p1.m_a = 100;
	person p2;
	p2.m_a = 150;
	cout << p1.m_a << endl;
}
//静态成员变量同样具有访问权限，写在private下就不可在外部访问


·静态成员函数
	1.所有对象公用一个函数
	2.静态成员函数只能用静态成员变量作为参数