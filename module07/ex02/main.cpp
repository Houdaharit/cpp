#include "Array.hpp"

int main()
{
	unsigned int n = 5;
	Array<int> array(n);
	for (int i = 0; i < array.size(); i++)
		array.setValues(i, i);
	for (int i = 0; i < array.size(); i++ )
		std::cout << array[i] << std::endl;
}
