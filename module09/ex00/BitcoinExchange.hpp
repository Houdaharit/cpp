#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <cstring>

void    remove_comma(std::string& value);
std::string trim_front(std::string& str);
std::string trim_back(std::string &str);
void	insert_data(std::map<std::string, float>& map, std::string line);
std::map<std::string, float> database_data(void);
int    date_value(std::string& line, std::string& date, std::string& value);
void    search_exchange_rate(std::string& date, float& value, std::map<std::string, float>& data);
int check_value_date(std::string date, float& value);
void    display(char *filename);
#endif

