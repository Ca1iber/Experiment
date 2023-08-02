·如果用户定义有参构造，编译器不再提供默认无参构造，但提供默认拷贝构造
·如果用户定义拷贝构造函数，则不再提供其他默认构造函数

class person
{
  public:
  int m_age;
  person(const &p)
  {
    ......; 
  }
}