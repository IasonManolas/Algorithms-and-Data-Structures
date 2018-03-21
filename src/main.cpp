#include <iostream>
#include "forwardlist.hpp"

using namespace std;
int main() {
	ForwardList<double> l;
	cout << "Size:" << l.size() << endl;
	for (int i = 0; i < 10; ++i) {
		l.push_front(i);
	}
	cout << "Size:" << l.size() << endl;
	l.print();
	cout << "Value at 1:" << l.value_at(1) << endl;

	cout << "pop front " << l.pop_front() << endl;
	l.print();

	cout << "front:" << l.front() << endl;

	l.insert(4, 99);
	l.print();
	l.erase(4);
	l.print();
	return 0;
}
