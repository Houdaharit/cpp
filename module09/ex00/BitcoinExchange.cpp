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

std::map<std::string, std::string> insert_data(std::map<std::string, std::string>& map, std::string line, const char* sep)
{
	int pos;
	std::string date;
	std::string value;

	pos = line.find(sep);
	date = line.substr(0, pos);
	date = strtrim(date);
	if (pos < 0)
		value = "";
	else
	{
		value = line.substr(pos + 1, line.size());
		value = strtrim(value);
	}
	map.insert(std::pair<std::string, std::string>(date, value));
	return map;
}

std::map<std::string, std::string> database_data(void)
{
	std::ifstream database;
	std::string line;
	std::map<std::string, std::string> data;

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

void	date_value(std::string& line, std::string& date, int& value)
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
		value = stoi(temp);
	}
}

void	search_exchange_rate(std::string& date, int& value, std::map<std::string, std::string>& data)
{
	std::map<std::string,std::string>::iterator it;
	std::map<std::string,std::string>::iterator temp;

	it = data.begin();
	while (it != data.end() && it->first != date)
		++it;
	if (it->first == date)
		std::cout << date << " => " << value << " = " << value * stoi(it->second) << std::endl;
	else
	{
		it = data.begin();
		int min = INT_MAX;
		while (it != data.end())
		{
			if (abs(date.compare(it->second)) < min)
			{
				min = abs(date.compare(it->second));
				temp = it;
			}
			++it;
		}
		std::cout << date << " => " << value << " = " << value * stoi(temp->second) << std::endl;
	}
}

void	display(char *filename, std::map<std::string, std::string>& data)
{
	std::ifstream file;
	std::string line;
	std::string date;
	int value;

	file.open(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	while(getline(file, line))
	{
		date_value(line, date, value);
		/*if (check_value_date(date, value) == -1)
			continue;*/
		search_exchange_rate(date, value, data);
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
	}
	return 0;
}
