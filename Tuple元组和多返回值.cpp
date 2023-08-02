#include<iostream>
#include<string>
#include<tuple>

std::tuple<std::string, int>CreatePerson()
{
	std::string name;
	int age;
	std::cin >> name >> age;
	return { name,age };
}

std::ostream& operator<<(std::ostream& stream, const std::tuple<std::string, int>& Tuple)
{
	stream << std::get<0>(Tuple) <<',' << std::get<1>(Tuple) << std::endl;
	return stream;
}

int main()
{
	auto Person=CreatePerson();
	std::cout <<Person << std::endl;
	auto [name, age] = CreatePerson();
	std::cout << name <<',' << age << std::endl;
	std::cin.get();
}