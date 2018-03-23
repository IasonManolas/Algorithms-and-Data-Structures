#include <iostream>
#include "queue.hpp"

using namespace std;
int main() {
	Queue<size_t> q;
	for (int i = 0; i < 15; ++i) {
		q.enqueue(i);
	}
	for (int i = 0; i < 15; ++i) {
		q.print();
		q.dequeue();
	}
	return 0;
}
