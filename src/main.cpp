#include <iostream>
#include "vector.hpp"

int main() {
	Vector<double> v;
	std::cout << "Size:" << v.size() << std::endl;
	std::cout << "Capacity:" << v.capacity() << std::endl;
	for (int i = 0; i < 10; i++) {
		v.push(i / 10.0);
	}
	v.print();
	std::cout << "Size:" << v.size() << std::endl;
	std::cout << "Capacity:" << v.capacity() << std::endl;
	v.insert(2, 99);
	v.print();
	std::cout << "Size:" << v.size() << std::endl;
	std::cout << "Capacity:" << v.capacity() << std::endl;
	v.prepend(99);
	v.print();
	std::cout << "Size:" << v.size() << std::endl;
	std::cout << "Capacity:" << v.capacity() << std::endl;

	v.remove(99);
	v.print();
	std::cout << "Size:" << v.size() << std::endl;
	std::cout << "Capacity:" << v.capacity() << std::endl;

	std::cout << "Find 3:" << v.find(3) << std::endl;
	return 0;
}
