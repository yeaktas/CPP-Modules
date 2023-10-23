/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:43 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 16:39:32 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

class BitcoinExchange {
    public:
        std::map<std::string, double> _data;
        std::map<std::string, double> _exchange;

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &b);
        BitcoinExchange& operator=(const BitcoinExchange &b);

        void readData();
        bool    DateCheck(std::string key_s);
        bool    AlphCheck(std::string value);
        double  give_back_data(std::string key, double value);
};

#endif