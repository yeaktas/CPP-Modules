/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:40 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 16:47:49 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}
BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) {
    *this = b;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &b) {
    this->_data = b._data;
    this->_exchange = b._exchange;
    return *this;
}

/* void BitcoinExchange::printMap() {
	std::map<std::string, double>::iterator it;
	for(it = _data.begin(); it != _data.end(); ++it){
		std::cout << it->first << " -- " << it->second << std::endl;
	}
} */

void BitcoinExchange::readData() {
    std::ifstream file("data.csv");
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::istringstream ss(line);
            std::string key;
            double value;
            if(std::getline(ss, key, ',') && ss >> value){
                _data[key] = value;
            }
        }
        file.close();
    }
    else {
        std::cerr << "Error: Data file is not opened!" << std::endl;
    }
}

double BitcoinExchange::give_back_data(std::string key, double value) {
    std::map<std::string, double>::iterator it = _data.upper_bound(key);
    if (it != _data.begin())
        return((--it)->second * value);
    return(0);
}

bool    BitcoinExchange::DateCheck(std::string key_s) {
    std::string date_day;
    std::string date_month;
    std::string date_year;
    size_t pos1;
    size_t pos2;

    pos1 = key_s.find("-");
    date_year = key_s.substr(0, pos1);
    pos2 = key_s.find("-", pos1 + 1);
    date_month = key_s.substr(pos1 + 1, pos2 - pos1 - 1);
    date_day = key_s.substr(pos2 + 1);
    if(date_year.length() == 4 || date_month.length() == 2 || date_day.length() == 2) {
        if(std::atoi(date_year.c_str()) <= 2008)
            ;
        else if(std::atoi(date_month.c_str()) > 12 || std::atoi(date_month.c_str()) < 1)
            ;
		else if(std::atoi(date_day.c_str()) > 31 || std::atoi(date_day.c_str()) < 1 )
            ;
		else if(std::atoi(date_year.c_str()) == 2009 && std::atoi(date_month.c_str()) == 1 && std::atoi(date_day.c_str()) == 1)
            ;
		else if(std::atoi(date_year.c_str()) == 2022) {
                if(std::atoi(date_month.c_str()) == 3)
			{
				if(std::atoi(date_day.c_str()) > 29)
                    ;
			}
			else if(std::atoi(date_month.c_str()) > 3)
                ;
		}
		else if(std::atoi(date_year.c_str()) > 2022)
            ;
		else
			return (true);
		return (false);
	}
	else
		return (false);
}

bool BitcoinExchange::AlphCheck(std::string value) {
    for(unsigned long i = 0; i < value.length(); i++) {
        if(isalpha(value[i])){
           return(false); 
        }
    }
    return(true);
}
