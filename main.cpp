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
	std::vector<int> v;
	std::cout << v.max_size() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	v.clear();
	return 0;
}
