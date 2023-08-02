class Phone
{
public:
	Phone(string PhoneName)
	{
		mPhoneName = PhoneName;
	}
	
	string mPhoneName;
};
class person
{
public:
	person(string name, string phone) :mName(name), mPhone(phone)
	{
		;
	}
	string mName;
	Phone mPhone;
};
void test()
{
	person p("ZhangSan", "iPhone");
	cout << p.mName << "的手机是" << p.mPhone.mPhoneName << endl;
}

构造顺序：先构造对象成员，再构造自身
析构顺序相反