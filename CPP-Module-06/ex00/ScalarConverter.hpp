/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:04:29 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/08 05:48:32 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter {

	public:
		ScalarConverter();
		ScalarConverter(const std::string &); //bunu sor
		ScalarConverter(const ScalarConverter &); //bunu sor
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &);

		static void convert(std::string);
};

#endif