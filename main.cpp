#include "vector.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include "pair.hpp"

class Test
{
public:
	Test() { std::cout << this << " test constructed" << std::endl; }
	~Test() { std::cout << this << " test destructed" << std::endl; }
};

int main()
{
	ft::vector<std::string> v;
	v.push_back("Zero");
	v.push_back("One");
	v.push_back("Two");
	v.push_back("Three");
	v.push_back("Four");
	v.push_back("Five");
	std::cout << v.at(3) << std::endl;
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;
	std::cout << v[3] << std::endl;
	std::cout << v[5] << std::endl;
	v.clear();	
	return 0;
}

