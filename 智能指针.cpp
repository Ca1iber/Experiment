//
#include<string>
#include <iostream>
#include <memory>
//#include <vector>
using namespace std;

int* CreateArray()
{
	int array[50];//错误，创建出来的array并没有被分配到堆区而是分配到了栈区，在作用域结束后就会销毁
	int* array1 = new int[50];//正确，new创建出来的空间会被分配到堆区
	//或是将函数中创建的数组的值复制到存放于堆区的数组中
	return array;
}

class Entity
{
public:
	 Entity()
	{
		cout<<"Constructed Entity"<<endl;
	}
	 ~Entity()
	 {
		 cout << "Destroyed Entity" << endl;
	 }
	 void Print()
	 {
		 ;
	 }
};
int main()
{
	unique_ptr<Entity> enty(new Entity());//超出作用域时，指针将会被销毁同时释放内存，不需要调用delete
	shared_ptr<Entity> sharedEntity=make_shared<Entity>();
	shared_ptr<Entity> se0 = sharedEntity;
	enty->Print();
}

