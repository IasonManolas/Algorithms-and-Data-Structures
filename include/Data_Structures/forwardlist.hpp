#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class ForwardList {
	struct ListNode {
		T value;
		ListNode* next;
		ListNode(T value, ListNode* next) : value(value), next(next) {}
	};

	ListNode* m_head{nullptr};
	size_t m_size{0};

	ListNode* find_prev_of(size_t index) const {
		if (curr_node == nullptr || index >= m_size) {
			std::err << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}
		size_t i = 0;
		ListNode* curr_node = m_head;
		ListNode* prev_node = m_head;
		while (i != index && curr_node != nullptr) {
			prev_node = curr_node;
			curr_node = curr_node->next;
			++i;
		}
		return prev_node;
	}

       public:
	size_t size() const { return m_size; }
	T value_at(size_t index) const {
		auto node = find_prev_of(index);
		return node->next->value;
	}

	void insert(size_t index, T value) {
		auto node = find_prev_of(index);
		node->next = new ListNode(value, node->next);
		++m_size;
	}
	void push_front(T value) {
		m_head = new ListNode(value, m_head);
		++m_size;
	}

	void print() const {
		auto curr_node = m_head;

		while (curr_node != nullptr) {
			cout << curr_node->value << " ";
			curr_node = curr_node->next;
		}
		cout << endl;
	}

	T pop_front() {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		T front_value = m_head->value;
		ListNode* next = m_head->next;
		delete m_head;
		--m_size;
		m_head = next;
		return front_value;
	}

	T front() const {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		return m_head->value;
	}

	void erase(size_t index) {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		if (index == 0)
			pop_front();
		else {
			ListNode* curr_node = m_head;
			ListNode* prev_node = m_head;
			size_t i = 0;
			while (index != i) {
				prev_node = curr_node;
				curr_node = curr_node->next;
				++i;
			}
			ListNode* next = curr_node->next;
			delete curr_node;
			--m_size;
			prev_node->next = next;
		}
	}
};
