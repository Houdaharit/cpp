#ifndef RNP_HPP
#define RNP_HPP
#include <iostream>
#include <list>
#include <cstring>

std::string erase_space(char*);
int insert_data(std::string&, std::list<int>&, std::list<char>&);
int error_msg();
int calcul(std::list<int>&, std::list<char>&);

#endif
