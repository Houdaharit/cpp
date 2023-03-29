#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>

void    remove_comma(std::string& value);
std::string trim_front(std::string& str);
std::string trim_back(std::string &str);
std::map<std::string, float> insert_data(std::map<std::string, float>& map, std::string line, const char* sep);
std::map<std::string, float> database_data(void);
void    date_value(std::string& line, std::string& date, float& value);
void    search_exchange_rate(std::string& date, float& value, std::map<std::string, float>& data);
int check_value_date(std::string date, float& value);
void    display(char *filename, std::map<std::string, float>& data);
#endif

