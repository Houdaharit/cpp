#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>

void	remove_comma(std::string& value)
{
	int pos;

	pos = value.find(",");
	value[pos] = '.';
}

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

std::map<std::string, float> insert_data(std::map<std::string, float>& map, std::string line, const char* sep)
{
	int pos;
	std::string date;
	std::string temp;
	float value;

	pos = line.find(sep);
	date = line.substr(0, pos);
	date = strtrim(date);
	if (pos < 0)
		value = 0;
	else
	{
		temp = line.substr(pos + 1, line.size());
		temp = strtrim(temp);
		value = atof(temp.c_str());
	}
	map.insert(std::pair<std::string, float>(date, value));
	return map;
}

std::map<std::string, float> database_data(void)
{
	std::ifstream database;
	std::string line;
	std::map<std::string, float> data;

	database.open("data.csv");
	if (!database)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	while(getline(database, line))
		insert_data(data, line, ",");
	return (data);
}

void	date_value(std::string& line, std::string& date, float& value)
{
	int pos;
	std::string temp;

	pos = line.find("|");
	date = line.substr(0, pos);
	date = strtrim(date);
	if (pos < 0)
		value = 0;
	else
	{
		temp = line.substr(pos + 1, line.size());
		temp = strtrim(temp);
		remove_comma(temp);
		value = atof(temp.c_str());
	}
}

void	search_exchange_rate(std::string& date, float& value, std::map<std::string, float>& data)
{
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator temp;

	it = data.begin();
	while (it != data.end() && it->first != date)
		++it;
	if (it->first == date)
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else
	{
		it = data.begin();
		temp = it;
		while (it != data.end() && date > it->first)
		{
			temp = it;
			++it;
		}
		std::cout << date << " => " << value << " = " << value * temp->second << std::endl;
	}
}

int	check_date(std::string date[])
{
	if (atoi(date[0].c_str()) <= 0 || atoi(date[0].c_str()) > 9999)
		return -1;
	if (atoi(date[1].c_str()) <= 0 || atoi(date[1].c_str()) > 12)
		return -1;
	if (atoi(date[2].c_str()) <= 0 || atoi(date[2].c_str()) > 31)
		return -1;
	return 1;
}
int	check_value_date(std::string date, float& value)
{
	int check = -1;
	int	pos;
	std::string tmp[3];
	int index = 0;

	(void)date;
	if (value < 0)
		std::cerr << "Error: not a positive value." << std::endl;
	else if (value > 100)
		std::cerr << "Error: too large value." << std::endl;
	else
		check = 1;
	pos = date.find("-");
	while (index < 3)
	{
		tmp[index] = date.substr(0, pos);
		date = date.substr(pos + 1, date.size());
		pos= date.find("-");
		index++;
	}
	return check;
}


void	display(char *filename, std::map<std::string, float>& data)
{
	std::ifstream file;
	std::string line;
	std::string date;
	float value;

	file.open(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	while(getline(file, line))
	{
		date_value(line, date, value);
		if (check_value_date(date, value) == -1)
			continue;
		search_exchange_rate(date, value, data);
	}
}

/*int main(int argc, char **argv)
  {
  (void)argv;
  if (argc > 1)
  {
  std::map<std::string, float> data;
  data = database_data();
  display(argv[1], data);
  }
  return 0;
  }*/
