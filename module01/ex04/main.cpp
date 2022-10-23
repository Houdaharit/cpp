#include "replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::string	line;
	char new_file[256] = {0};

	if (argc < 4)
	{
		std::cerr << "Not enough parameters: " << 4 - argc << " parameters needed\n";
		std::cerr << "File name\ts1\ts2\n";
		return (1);
	}
	file.open(argv[1]);
	if (!file)
	{
		std::cerr << argv[1] << " can't be opened!" << std::endl;
		return (1);
	}
  	strcpy(new_file, argv[1]);
    strcat(new_file, ".replace");
	while (getline(file, line))
		replace(line, new_file, argv[2], argv[3]);
	file.close();
}
