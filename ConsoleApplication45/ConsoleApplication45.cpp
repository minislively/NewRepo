#include <iostream>
#include <cstddef>

using namespace std;

class IntArray
{
private:
	int* m_Array;
	int m_Length;

public:
	IntArray(int length)
	{
		m_Array = new int[static_cast<size_t>(length)]{};
		m_Length = length;

	}
	~IntArray()
	{
		delete[] m_Array;
	}
	void SetValue(int index, int value)
	{
		m_Array[index] = value;
	}
	int GetValue(int inudex)
	{
		return m_Array[inudex];
	}
	int GetLength()
	{
		return m_Length;
	}
};

int main()
{
	IntArray ar(10);

	for (int count = 0; count < ar.GetLength(); ++count)
	{
		ar.SetValue(count, count + 1);
	}
	cout << "The value of element 5 is : " << ar.GetValue(5) << "\n";
	return 0;
}