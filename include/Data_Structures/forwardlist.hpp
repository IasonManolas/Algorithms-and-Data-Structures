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
	ListNode* m_tail{nullptr};
	size_t m_size{0};

	ListNode* find_prev_of(size_t index) const {  // Is this a bad idea?
		size_t i = 0;
		ListNode* curr_node = m_head;
		ListNode* prev_node = m_head;
		while (i != index) {
			prev_node = curr_node;
			curr_node = curr_node->next;
			++i;
		}
		return prev_node;
	}

       public:
	~ForwardList() {
		ListNode* curr_node = m_head;

		while (curr_node != nullptr) {
			auto next = curr_node->next;
			delete curr_node;
			curr_node = next;
		}
	}
	size_t size() const { return m_size; }
	T value_at(size_t index) const {
		if (index >= m_size) {
			std::cerr << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}
		auto node = find_prev_of(index);
		return node->next->value;
	}

	void insert(size_t index, T value) {
		if (index > m_size) {
			std::cerr << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}

		if (index == m_size - 1) {
			push_back(value);
		} else if (index == 0) {
			push_front(value);
		} else {
			auto node = find_prev_of(index);
			node->next = new ListNode(value, node->next);
			++m_size;
		}
	}
	void push_front(T value) {
		m_head = new ListNode(value, m_head);
		++m_size;
		if (m_size == 1) m_tail = m_head;
	}

	void push_back(T value) {
		ListNode* new_node = new ListNode(value, nullptr);
		if (m_size == 0) {
			m_tail = new_node;
			++m_size;
			m_head = m_tail;
		} else {
			m_tail->next = new_node;
			m_tail = new_node;
			++m_size;
		}
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

	T pop_back() {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		T back_value = m_tail->value;
		ListNode* prev_of_last = find_prev_of(m_size - 1);
		delete m_tail;
		--m_size;
		m_tail = prev_of_last;
		m_tail->next = nullptr;
		return back_value;
	}

	T front() const {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		return m_head->value;
	}

	T back() const {
		if (m_head == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		return m_tail->value;
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

	void reverse() {
		if (m_head != nullptr) {
			ListNode* curr_node = m_head;
			ListNode* next = curr_node->next;
			ListNode* prev = curr_node;
			curr_node->next = nullptr;
			curr_node = next;

			while (curr_node != nullptr) {
				next = curr_node->next;
				curr_node->next = prev;
				prev = curr_node;
				curr_node = next;
			}
			m_tail = m_head;
			m_head = prev;
		}
	}
};
