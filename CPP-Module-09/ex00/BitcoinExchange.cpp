/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:55:06 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/21 15:10:53 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void Bitcoin::printMap() {
	std::map<std::string, double>::iterator it;
	for(it = _data.begin(); it != _data.end(); ++it){
		std::cout << it->first << " -- " << it->second << std::endl;
	}
}

void Bitcoin::readData() {
	std::ifstream data("data.csv");
	if(data.is_open())
	{
		std::string line;
		std::getline(data, line);
		if(line.compare("date,exchange_rate"))
			throw MyExc("Error: you dont have date, exchange_rate");
		while(std::getline(data, line)) {
			std::stringstream ss(line);
			std::string time;
			double value;
			std::getline(ss, time, ',');
			ss >> value;
			this->_data[time] = value;
		}
		data.close();
	}
	else
		throw MyExc("Error: data is not finded");
}

double Bitcoin::calculate(std::string key, double value) {
	int diff = 0;
    if (key < _data.begin()->first)
        return (0);
    else {
        std::map<std::string, double>::iterator prev = _data.begin();
        std::map<std::string, double>::iterator it;
        for (it = _data.begin(); it != _data.end(); ++it) {
			
            if (it->first >= key) {
                if (it->first == key)
                    return (value * it->second);
				else if ()
                else
                    return (value * prev->second);
            }
            prev = it;
        }
    }
    return (1);
}

void Bitcoin::readInput(char **av) {
	std::ifstream inp(av[1]);
	std::string line;
	std::getline(inp, line);
	while(std::getline(inp, line)) {
		std::istringstream iss(line);
		std::string key, value;
		value.clear();
		key.clear();
		if(std::getline(iss, key, '|') && iss >> value) {
			std::stringstream dob(value);
			double doub;
			dob >> doub;
			this->_input[key] = doub;
		} else {
			std::cout << line << std::endl;
		}
		std::cout << key << " ==> " << this->_input[key] << " = " << this->calculate(key, this->_input[key]) << std::endl;
		iss.clear();
	}
}