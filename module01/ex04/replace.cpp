#include "replace.hpp"

void	replace(std::string line, char *new_file_name, char *s1, char *s2)
{
	std::ofstream	new_file;
	size_t 			pos;
	std::string		str2;
	std::string		str;

	new_file.open(new_file_name, std::ios_base::app);
	if (!new_file)
		std::cerr << "Hell no!\n";
	pos = line.find(s1);
	if (pos != std::string::npos)
	{
		str = line.substr(0, pos);
		str2 = line.substr(pos + strlen(s1));
		new_file << str + s2 + str2 << std::endl;
	}
	else
		new_file << line << std::endl;
	new_file.close();
}
