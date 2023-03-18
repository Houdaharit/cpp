#include <iostream>
#include <map>
#include <fstream>

std::multimap insert_data(std::multimap& multimap)
{

}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::string line;
	std::multimap<std::string, int> multimap;

	(void)argc;
	file.open(argv[1]);
	if (!file)
	{
		std::cerr << "Error: could not open file!" << std::endl;
		return (1);
	}
	while(getline(file, line))
		insert_data(multimap);
}
