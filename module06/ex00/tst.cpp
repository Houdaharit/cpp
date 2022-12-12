#include <iostream>
#include <string>
#include <exception>

int main(int argc, char**argv)
{
		std::string str(argv[1]);
		int i = std::stoi(str);
		std::cout << i << std::endl;
	/*catch(std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}*/
}
