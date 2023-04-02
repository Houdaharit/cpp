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

int	date_value(std::string& line, std::string& date, float& value)
{
	int pos;
	std::string temp;

	pos = line.find("|");
	if (pos < 0)
		pos = line.find(",");
	date = line.substr(0, pos);
	date = strtrim(date);
	if (date == "date")
		return 0;
	if (pos < 0)
		value = 0;
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
		if (value > 0)
			std::cout << date << " => " << value << " = " << value * temp->second << std::endl;
		else
			std::cerr << "Error: No value or NULL value" << std::endl;
	}
}

int	check_date(std::string date[])
{
	int day = atoi(date[2].c_str());
	int month = atoi(date[1].c_str());
	int year = atoi(date[0].c_str());

	if (year <= 0 || year > 9999)
		return -1;
	if (month <= 0 || month > 12)
		return -1;
	if (day <= 0 || day > 31)
		return -1;
	else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11 ) && day == 31)
		return -1;
	else if (month == 2)
	{
		if (year % 4 != 0 && day == 29)
			return -1;
	}
	return 1;
}

int	check_value_date(std::string date, float& value)
{
	int check = -1;
	int	pos;
	std::string tmp[3];
	int index = 0;
	std::string temp(date);

	(void)date;
	if (value < 0)
		std::cerr << "Error: not a positive value." << std::endl;
	else if (value > 1000)
		std::cerr << "Error: too large value." << std::endl;
	else
		check = 1;
	pos = date.find("-");
	while (index < 3)
	{
		tmp[index] = temp.substr(0, pos);
		temp = temp.substr(pos + 1, date.size());
		pos = temp.find("-");
		index++;
	}
	if (check_date(tmp) == -1)
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
