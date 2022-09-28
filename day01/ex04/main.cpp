#include "replace.hpp"

int main(int argc, char **argv)
{
	std::fstream	file;
	if (argc < 4)
		return (1);
	file.open(argv[1], std::ios::in);
	if (!file)
		std::cerr << argv[1] << " can't be opened!" << std::endl;
}
