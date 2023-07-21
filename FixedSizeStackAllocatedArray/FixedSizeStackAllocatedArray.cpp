#include <iostream>

template<typename T, size_t S>
class Array
{
public:
	constexpr size_t Size() const { return S; } // const - can't change the inner object
	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index) const { return m_Data[index]; }
	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }
private:
	T m_Data[S];
};

int main()
{
	int size = 5;
	Array<int, 5> intData;
	memset(&intData[0], 0, intData.Size() * sizeof(int));
	static_assert(intData.Size() < 10, "Size is too large!"); // catch bugs at compile time
	intData[1] = 5;
	for (size_t i = 0; i < intData.Size(); i++)
	{
		std::cout << intData[i] << std::endl;
	}
	
	Array<std::string, 2> stringData;
	stringData[0] = "Stack";
	stringData[1] = "Array";
	for (size_t i = 0; i < stringData.Size(); i++)
	{
		std::cout << stringData[i] << std::endl;
	}
}