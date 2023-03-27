#include <iostream>
#include <map>
#include <fstream>

std::string trim_front(std::string& str)
{
	int i = 0;

	while(str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i])
		str = str.substr(i, str.size());
	return str;
}

std::string trim_back(std::string &str)
{
	int i = 0;

	while (str[i] && (str[i] != 32 && str[i] != '\t' && str[i] != '\n'))
		i++;
	if (str[i])
		str = str.substr(0, i);
	return str;
}

std::string strtrim(std::string& str)
{
	trim_front(str);
	trim_back(str);
	return str;
}

std::multimap<std::string, std::string> insert_data(std::multimap<std::string, std::string>& multimap, std::string line)
{
	int pos;
	std::string date;
	std::string value;

	pos = line.find(",");
	date = line.substr(0, pos);
	date = strtrim(date);
	if (pos < 0)
		value = "";
	else
	{
		value = line.substr(pos + 1, line.size());
		value = strtrim(value);
	}
	multimap.insert(std::pair<std::string, std::string>(date, value));
	return multimap;
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::ifstream database;
	std::string line;
	std::multimap<std::string, std::string> data;
	std::multimap<std::string, std::string>::iterator it;

	(void)argc, (void)argv;
	/*file.open(argv[1]);
	  if (!file)
	  {
	  std::cerr << "Error: could not open file!" << std::endl;
	  return (1);
	  }
	  while(getline(file, line))
	  insert_data(multimap, line);
	  it = multimap.begin();
	  while(it != multimap.end())
	  {
	  std::cout << it->first << " " << it->second << std::endl;
	  ++it;
	  }*/

	database.open("data.csv");
	if (!database)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;	
	}
	while(getline(database, line))
		insert_data(data, line);
	it = data.begin();
	while(it != data.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}
}
