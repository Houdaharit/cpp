#include "Array.hpp"

int main()
{
	//Integer
	unsigned int n = 5;
	Array<int> array(n);

	for (int i = 0; i < array.size(); i++)
		array.setValues(i, i);
	for (int i = 0; i < array.size(); i++ )
		std::cout << array[i] << std::endl;
	try
	{
		std::cout << array[6] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//string

	Array<std::string> array2(n);
	for (int i = 0; i < array2.size(); i++)
		array2.setValues(i, "hello");
	for (int i = 0; i < array2.size(); i++ )
		std::cout << array2[i] << std::endl;
	try
	{
		std::cout << array2[6] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
