#include "forwardlist.hpp"
template <typename T>
class Queue {
	ForwardList<T> l;

       public:
	Queue() {}

	void enqueue(T value) { l.push_back(value); }

	T dequeue() { return l.pop_front(); }

	bool empty() const { return l.size() == 0; }

	void print() const { l.print(); }
};
