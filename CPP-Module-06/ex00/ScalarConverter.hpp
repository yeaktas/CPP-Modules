/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:04:29 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 14:47:21 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>

class ScalarConverter {
	private:
        std::string sc;
	public:
		ScalarConverter();
		ScalarConverter(const std::string &);
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &);

		static void convert(std::string str);
		static bool is_it_for_science(std::string &s);
		static bool is_wrong_number(std::string &s);
};

#endif