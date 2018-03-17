template <typename T>
class Vector {
	static const unsigned int initial_size = 2;

	T* arr;
	unsigned int m_capacity{initial_size};
	unsigned int m_size{0};

	void resize(unsigned int new_capacity) {
		T* new_array = new T[new_capacity];

		for (int i = 0; i < m_size; ++i) {
			new_array[i] = arr[i];
		}
		m_capacity = new_capacity;
		arr = new_array;
	}

	void shift_right(int index) {
		for (int i = m_size - 1; i >= index; --i) {
			arr[i + 1] = arr[i];
		}
		++m_size;
	}

	void shift_left(int index) {
		for (int i = index; i < m_size - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		--m_size;
	}

       public:
	Vector() { arr = new T[initial_size]; }
	~Vector() { delete[] arr; }

	void print() const {
		for (unsigned int i = 0; i < m_size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	unsigned int size() const { return m_size; }

	unsigned int capacity() const { return m_capacity; }

	bool is_empty() const { return m_size == 0; }

	T at(unsigned int index) const { return arr[index]; }

	void push(T item) {
		if (m_size == m_capacity) {
			resize(2 * m_capacity);
		}
		arr[m_size] = item;
		++m_size;
	}

	void insert(unsigned int index, T value) {  // what if index>m_size
		if (m_size == m_capacity) resize(2 * m_capacity);
		shift_right(index);
		arr[index] = value;
	}

	void prepend(T value) { insert(0, value); }

	T pop() {
		T value = arr[m_size - 1];
		--m_size;
		if (m_size == m_capacity / 4) resize(m_capacity / 2);
		return value;
	}

	void delete_at(unsigned int index) {
		shift_left(index);
		if (m_size == m_capacity / 4) resize(m_capacity / 2);
	}

	void remove(T value) {
		for (unsigned int i = 0; i < m_size;
		     ++i) {  // could any problems arise because delete_at
			     // alters
			     // m_size?
			if (arr[i] == value) {
				delete_at(i);
				--i;  // is this a bad practice? Any
				      // alternatives?
			}
		}
	}

	int find(T value) {
		for (unsigned int i = 0; i < m_size; ++i) {
			if (arr[i] == value) return i;
		}
		return -1;
	}
};
