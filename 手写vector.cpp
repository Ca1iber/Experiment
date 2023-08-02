#include<iostream>

class String
{
public:
	String() = default;

	String(const char* str)
	{
		std::cout << "Created!" << std::endl;
		m_Size = strlen(str);
		m_Data = new char[m_Size];
		memcpy(m_Data, str, m_Size);
	}

	String(const String& str)
	{
		std::cout << "Copied!" << std::endl;
		m_Size = str.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, str.m_Data, m_Size);
	}

	String(String&& other)	noexcept
	{
		std::cout << "Moved!" << std::endl;
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		//接管原来的旧字符串，处理原来的指针，以免在释放内存时将数据误删
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator=(String&& other) noexcept
	{
		delete[]  m_Data;
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;

	}
	~String()
	{
		std::cout << "Destroyed!" << std::endl;
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		std::cout << "\n" << std::endl;
	}

private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)
		:m_Name(name)
	{
	}

	Entity(String&& name)
		:m_Name(std::move(name))
	{
	}

	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	Entity en("Cherno!");
	en.PrintName();

	String str = "Hello";
	String dst = std::move(str);

	std::cin.get();
