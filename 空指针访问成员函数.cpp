class person
{
public:
	void ShowClass()
	{
		cout << "the name of this class is person" << endl;
	}
	void ShowAge()
	{
		cout<<"the age of this class is "<<age;
	}
	int age;
};
void test()
{
	person* p = NULL;
	p->ShowClass();
	p->ShowAge();
}
//ShowClass函数不会导致崩溃而ShowAge函数会导致崩溃，因为在ShowAge中输出的age前默认带有this->指针，而p本身是一个空指针，里面没有任何成员，所以
会崩溃，最好的办法就是增强代码的健壮性