#include "BitcoinExchange.hpp"

void	remove_comma(std::string& value)
{
	int pos;

	pos = value.find(",");
	if (pos > 0)
		value[pos] = '.';
}

int	is_number(std::string &value)
{
	int i = 0;
	int com = -1;

	while(value[i])
	{
		if (!isdigit(value[i]) && strchr(".,", value[i]))
		{
			if (com == -1)
				com = 1;
			else
				return 0;
		}
		else if (!isdigit(value[i]))
			return 0;
		i++;
	}
	return 1;
}

int is_int(std::string& value)
{
	int i = 0;

	while(value[i])
	{
		if (!isdigit(value[i]))
			return 0;
		i++;
	}
	return 1;

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

std::string trim_back(std::string& str)
{
	char whitespace[] = " \n\r\t\f\v";
	int i = str.size() - 1;

	while (i > 0 && strchr(whitespace, str[i]))
		i--;
	if (!strchr(whitespace, str[i]))
		str =  str.substr(0, i + 1);
	return str;
}

std::string strtrim(std::string& str)
{
	trim_front(str);
	trim_back(str);
	return str;
}

void	insert_data(std::map<std::string, float>& map, std::string line)
{
	int pos;
	std::string date;
	std::string temp;
	float value;

	pos = line.find(",");
	date = line.substr(0, pos);
	date = strtrim(date);
	temp = line.substr(pos + 1, line.size());
	temp = strtrim(temp);
	value = atof(temp.c_str());
	map.insert(std::pair<std::string, float>(date, value));
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
	database.close();
	return (data);
}

void	search_exchange_rate(std::string& date, std::string& value, std::map<std::string, float>& data)
{
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator temp;
	float value_ = atof(value.c_str());

	it = data.begin();
	while (it != data.end() && it->first != date)
		++it;
	if (it != data.end() && it->first == date)
		std::cout << date << " => " << value_ << " = " << value_ * it->second << std::endl;
	else
	{
		it = data.begin();
		temp = it;
		while (it != data.end() && date > it->first)
		{
			temp = it;
			++it;
		}
		std::cout << date << " => " << value_ << " = " << value_ * temp->second << std::endl;
	}
}

void date_(std::string& date, std::string& str)
{
	int pos = date.find("-");
	str = date.substr(0, pos);
	date = date.substr(pos + 1, date.size());
}

int	check_date(std::string date)
{
	std::string day;
	std::string month;
	std::string year;

	date_(date, year);
	date_(date, month);
	date_(date, day);
	if (!is_int(year) || !is_int(month) || !is_int(day))
		return -1;
	int m = atoi(month.c_str());
	int d = atoi(day.c_str());
	int y = atoi(year.c_str());
	if (y <= 0 || y > 9999 || m <= 0 || m > 12 || d <= 0 || d > 31)
		return -1;
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
		return -1;
	else if (m == 2)
	{
		if (d > 29)
			return -1;
		if (y % 4 != 0 && d == 29)
			return -1;
	}
	return 1;
}

int	check_value_date(std::string date, std::string& value)
{
	int check = 1;
	int value_;

	if (is_number(value))
	{
		value_ = atof(value.c_str());
		if (value_ < 0)
		{
			std::cerr << "Error: not a positive value." << std::endl;
			check = -1;
		}
		else if (value_ > 1000)
		{
			std::cerr << "Error: too large value." << std::endl;
			check = -1;
		}
	}
	else
	{
		std::cerr << "Error: Bad input => " << value << std::endl;
		check = -1;
	}
	if (check_date(date) == -1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		check = -1;
	}
	return (check);
}

int	date_value(std::string& line, std::string& date, std::string& value)
{
	int pos;

	pos = line.find("|");
	if (pos < 0)
		pos = line.find(",");
	if (pos < 0)
	{
		date = line;
		if (check_date(date) == -1)
			std::cerr << "Error: bad input => " << date << std::endl;
		std::cerr << "Error: No value. => " << date << std::endl;
		return -1;
	}
	date = line.substr(0, pos);
	date = strtrim(date);
	if (date == "date")
		return -1;
	else
	{
		value = line.substr(pos + 1, line.size());
		value = strtrim(value);
		remove_comma(value);
		if (value == "value")
			return -1;
	}
	return check_value_date(date, value);
}


void	display(char *filename)
{
	std::ifstream file;
	std::string line;
	std::string date;
	std::string value;
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
		if (date_value(line, date, value) == -1)
			continue;
		search_exchange_rate(date, value, data);
		i++;
	}
	if (i == 0)
		std::cout << "Empty input file." << std::endl;
	file.close();
}

