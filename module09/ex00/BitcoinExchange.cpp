#include <iostream>
#include <map>
#include <fstream>

std::string strtrim(std::string& str)
{
	return str;
}

std::multimap<std::string, std::string> insert_data(std::multimap<std::string, std::string>& multimap, std::string line)
{
	int pos;
	std::string date;
	std::string value;

	pos = line.find("|");
	date = line.substr(0, pos);
	if (pos < 0)
		value = "";
	else
		value = line.substr(pos + 1, line.size());
	std::cout << value << std::endl;
	return multimap;
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::string line;
	std::multimap<std::string, std::string> multimap;

	(void)argc;
	file.open(argv[1]);
	if (!file)
	{
		std::cerr << "Error: could not open file!" << std::endl;
		return (1);
	}
	while(getline(file, line))
		insert_data(multimap, line);
}
