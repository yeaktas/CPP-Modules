/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:46:28 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/21 15:07:45 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <string>

class Bitcoin{

	private:
		std::map<std::string, double> _data;
		std::map<std::string, double> _input;

	public:
		void readData();
		void printMap();
		void readInput(char **av);
		double calculate(std::string key, double value);
};

class MyExc: public std::exception{
	private:
		const char* _msg;
	public:
		MyExc(const char* msg) : _msg(msg) {}
		const char* what() const throw() {
			return _msg;
		}
};

#endif