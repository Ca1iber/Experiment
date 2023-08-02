友元的目的就是让一个函数或类访问另一个类中的私有成员	关键词friend
友元的三种实现
·全局函数做友元
·类做友元
·成员函数做友元

·全局函数做友元
class Room
{
	friend void Friend(Room& building);

public:
	Room()
	{
		m_livingroon = "There are TV,sofa,tables and chairs";
		m_bedroom = "There are PC,gamepad,and bed";
	}
	string m_livingroon;
private:
	string m_bedroom;
	
};
void Friend(Room &building)
{
	cout << "your friend is now visiting your " << building.m_livingroon << endl;
	cout << "your friend is now visiting your " << building.m_bedroom << endl;
}


·类做友元