this指针指向被调用的成员函数所属的对象
·当形参和成员变量同名时，可以用this区分
·在类的非静态成员函数中返回对象本身可以用return *this

1.解决名称冲突
class person
{
public:
	person(int age)
	{
		this->age = age;
	}
	int age;
};

2.返回类本身用*this
	person& PersonAddAge(person &p)//注意返回类本身返回值类型要是类的引用，参数中也需要是类的引用
		//如果返回值会创建新对象，而不是调用对象本身
	{
		this->age += p.age;
		return *this;
	}
};
void test()
{
	person p1(18);
	person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//所谓链式编程

	cout << "p1的年龄为" << p2.age << endl;
}
