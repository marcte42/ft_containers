#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
	ft::vector<int> v;

	std::cout << v.size() << std::endl;
	v.reserve(10);
	return 0;
}
