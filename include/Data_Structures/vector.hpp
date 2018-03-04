template <typename T>
class Vector {
	static const unsigned int initial_size = 16;

	T arr[initial_size];
	unsigned int m_size{initial_size};

       public:
	unsigned int size() const { return sizeof(arr) / sizeof(arr[0]); }
};
