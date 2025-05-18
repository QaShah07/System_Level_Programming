#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	IntArray(int length)
	{
		assert(length>0);
		m_array = new int[static_cast<std::size_t>(length)]{};
		m_length = length;
	}
	// destructor
	~IntArray()
	{
		delete[] m_array;
	}
	// now getter and setter 
	void setValue(int index, int value) {m_array[index]=value; }
	int getValue(int index) { return m_array[index]; }

	int getLength()
	{
		return m_length;
	}
};

// main function to control this
int main()
{
	IntArray ar(10);
	for (int i = 0; i < ar.getLength(); ++i)
	{
		ar.setValue(i,i+1);
	}
	// print
	std::cout<<"The value of element 5 is: "<<ar.getValue(5)<<"\n";
	return 0;
}