#ifndef RNP_HPP
#define RNP_HPP
#include <iostream>
#include <vector>
#include <cstring>

std::string erase_space(char*);
int insert_data(std::string&, std::vector<int>&, std::vector<char>&);
int error_msg();
int calcul(std::vector<int>&, std::vector<char>&);

#endif
