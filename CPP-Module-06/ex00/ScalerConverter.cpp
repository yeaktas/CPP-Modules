/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:15:24 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/08 07:11:54 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const std::string &name){
	(void)name; //sor
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj){
	(void)obj;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj){

	(void)obj;
	return (*this);
}

void ScalarConverter::convert(std::string av1)
{
	double numd = 0;

	if (av1.length() == 1 && !std::isdigit(av1[0]))
		numd = static_cast<double>(av1[0]);
	else
		numd = std::strtod(av1.c_str(), NULL);

	std::cout << "char: ";
    if (!((numd < 0) || (numd > std::numeric_limits<char>::max()) || (numd != numd)))
	{
        if (std::isprint(static_cast<int>(numd)))
            std::cout << "\'" << static_cast<char>(numd) << "\'";
	    else
            std::cout << "Non displayable";
    }
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << "int : ";
    if (!((numd < std::numeric_limits<int>::min()) || (numd > std::numeric_limits<int>::max()) || (numd != numd)))
        std::cout << static_cast<int>(numd);
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << "float : " << static_cast<float>(numd);
    if (static_cast<float>(numd) - static_cast<long>(numd) == 0.0f)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double : " << numd;
    if (numd - static_cast<long>(numd) == 0.0)
        std::cout << ".0";
    std::cout << std::endl;
}