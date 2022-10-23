#include "replace.hpp"

std::string     replace(std::string line, char *s1, char *s2)
{
    size_t          pos = 0;
    std::string     str2;
    std::string     str;
    std::string     new_line;

    while (line.find(s1) != std::string::npos)
    {
        pos = line.find(s1);
        str = line.substr(0, pos);
        str2 = line.substr(pos + strlen(s1));
        new_line = str + s2 + str2;
        line = new_line;
    }
    return (line);
}

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream 	new_file;
	std::string	line;
	std::string file_name(argv[1]);	

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
	new_file.open(file_name + ".replace");
	if (!new_file)
	{
		std::cerr << file_name << " :file can't be opened!" << std::endl;
		return (1);
	}
	while (getline(file, line))
	{
		line = replace(line, argv[2], argv[3]);
		new_file << line << std::endl;
	}
	file.close();
	new_file.close();
}
