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
	std::cout << "Making vector" << std::endl;
	#ifdef DEBUG
	std::vector<Test> v;
	#else
	ft::vector<Test> v;
	#endif
	v.push_back(Test());
	v.pop_back();
	v.push_back(Test());
	v.pop_back();
	v.push_back(Test());
	v.push_back(Test());
	v.pop_back();
	v.clear();	
	return 0;
}

