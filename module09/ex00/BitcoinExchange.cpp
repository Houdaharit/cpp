#include "BitcoinExchange.hpp"

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
std::map<std::string, float> insert_data(std::map<std::string, float>& map, std::string line)
{
	int pos;
	std::string date;
	std::string temp;
	float value;

	pos = line.find(",");
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
		insert_data(data, line);
	return (data);
}

void	search_exchange_rate(std::string& date, float& value, std::map<std::string, float>& data)
{
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator temp;

	it = data.begin();
	while (it != data.end() && it->first != date)
		++it;
	if (it != data.end() && it->first == date)
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

int	check_date(std::string date)
{
	int day;
	int month;
	int year;
	int del;
	struct tm tm;

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return -1;
	std::istringstream str(date);
	str >> year >> del >> month >> del >> day;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return -1;
	else if (month == 2)
	{
		if (day > 29)
			return -1;
		if (year % 4 != 0 && day == 29)
			return -1;
	}
	return 1;
}

int	date_value(std::string& line, std::string& date, float& value)
{
	int pos;
	std::string temp;

	pos = line.find("|");
	if (pos < 0)
		pos = line.find(",");
	if (pos < 0)
	{
		std::cerr << "Error: No value." << std::endl;
		return 0;
	}
	date = line.substr(0, pos);
	date = strtrim(date);
	if (date == "date")
		return 0;
	else
	{
		temp = line.substr(pos + 1, line.size());
		temp = strtrim(temp);
		remove_comma(temp);
		if (temp == "value")
			return 0;
		value = atof(temp.c_str());
	}
	return 1;
}

int	check_value_date(std::string date, float& value)
{
	int check = -1;

	(void)date;
	if (value < 0)
		std::cerr << "Error: not a positive value." << std::endl;
	else if (value > 1000)
		std::cerr << "Error: too large value." << std::endl;
	else
		check = 1;
	if (check_date(date) == -1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		check = -1;
	}
	return check;
}

void	display(char *filename)
{
	std::ifstream file;
	std::string line;
	std::string date;
	float value;
	int i = 0;

	file.open(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::map<std::string, float> data = database_data();
	while(getline(file, line))
	{
		if (!date_value(line, date, value) || check_value_date(date, value) == -1)
			continue;
		search_exchange_rate(date, value, data);
		i++;
	}
	if (i == 0)
		std::cout << "Empty input file." << std::endl;
}

