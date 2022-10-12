#include "replace.hpp"

void	replace(std::string line, char *file_name, char *s1, char *s2)
{
	std::ofstream	new_file;
	char		new_file_name[256];
	size_t 		pos;
	std::string	str;
	std::string	str2;

	(void)s1, (void)s2;
	strncpy(new_file_name, file_name, sizeof(new_file_name - strlen(new_file_name) - 1));
	strncat(new_file_name, ".replace", sizeof(new_file_name - strlen(new_file_name) - 1));
	new_file.open(new_file_name, std::ios_base::app);
	if (!new_file)
		std::cerr << "Hell no!\n";
	pos = line.find(s1);
	if (pos != std::string::npos)
	{
		str = line.substr(0, pos);
		str2 = line.substr(pos + strlen(s1));
		new_file << str + s2 + str2;
		new_file << std::endl;
	}
	else
		new_file << line << std::endl;
	new_file.close();
}
