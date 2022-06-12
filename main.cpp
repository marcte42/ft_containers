#include "vector.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include "pair.hpp"

int main()
{
	std::vector<std::string> v;

	v.push_back("test");
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	v.push_back("best");
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	std::vector<std::string>::iterator it = v.begin();
	std::cout << "it.begin : " << *it << std::endl;
	v.push_back("rest");
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	it = v.begin();
	std::cout << "it.begin : " << *it << std::endl;
	

	return 0;
}

