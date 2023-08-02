//
#include<string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct MyStruct
{
	float x, y, z;
	MyStruct(float x, float y, float z)
		:x(x), y(y), z(z)
	{
		;
	}
	MyStruct(const MyStruct& mystruct)
		:x(mystruct.x),y(mystruct.y),z(mystruct.z)
	{
		cout << "Copy Constructed!" << endl;
	}
};


//ostream& operator<<(ostream& stream, const String& string)
//{
//	stream << string.m_Buffer;
//	return stream; 
//}

ostream& operator<<(ostream& stream, const MyStruct& my_struct)
{
	stream << my_struct.x << "," << my_struct.y << "," <<my_struct.z << endl;
	return stream;
}
int main()
{
	vector<MyStruct> mystructs ;
	mystructs.reserve(3);
/*	此情况下不会调用拷贝函数，不会有vector被复制
	mystructs.emplace_back( 1,2,3 );
	mystructs.emplace_back(4, 5, 6);
	mystructs.emplace_back(7, 8, 9);//拷贝构造
*/
/*	此情况下被复制6次
	mystructs.push_back({1,2,3});有参构造
	mystructs.push_back({4,5,6});有参构造
	mystructs.push_back(MyStruct(7,8,9));拷贝构造

*/
}

