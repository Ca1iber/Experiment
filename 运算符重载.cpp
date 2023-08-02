//
#include<string>
#include <iostream>
//#include <vector>
using namespace std;

struct Vec2
{
	float m_x, m_y;

	Vec2(float x,float y)
		:m_x(x), m_y(y)				//初始化Vec2对象x,y 
	{
		;
	}
	
	Vec2 Add(const Vec2& other) const
	{
		return Vec2(m_x + other.m_x, m_y + other.m_y); 	//加法函数，用于运算符重载
	}

	Vec2 Multiply(const Vec2& other) const
	{
		return Vec2(m_x * other.m_x, m_y * other.m_y);	//乘法函数，用于运算符重载
	}


	Vec2 operator+(const Vec2& other) const
	{
		return Add(other);				//+重载
	}
	Vec2 operator*(const Vec2& other) const
	{
		return Multiply(other);			//*重载
	}
};

ostream& operator<<(ostream& stream,const Vec2& other)
{
	stream << other.m_x << "," << other.m_y;		//<<重载
	return stream;					//ostream是一个标准库定义的类
}

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

ostream& operator<<(ostream& stream, const Entity& enty)
{
	stream << enty.x << "," <<enty.y;			//重载<<
	return stream;					
}

int main()
{
	//Vec2 position(4.0f, 4.0f);
	//Vec2 speed(1.0f, 1.0f);
	//Vec2 powerup(1.1f, 1.1f);
	//Vec2 result1 = position + speed * powerup;
	//Vec2 result2 = position.Add(speed.Multiply(powerup));
	//cout << result1 << endl;
	//cout << 1 << endl;
	Entity e(5, 6);
	cout << e << endl;
}
