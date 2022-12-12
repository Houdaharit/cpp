#include <iostream>
#include <sstream>
#include <cstdlib>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::stringstream str(argv[1]);
		float f;
		str >>f;
		if (str.fail())
			std::cout << "fail!" << std::endl;
		else
			std::cout << f << std::endl;
	}

}
