/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:20:06 by yaktas            #+#    #+#             */
/*   Updated: 2023/08/17 08:20:06 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main ( void ) {

    try
    {

        Bureaucrat hamdi("Bureaucrat Hamdi", 140);
        Bureaucrat sabri("Bureaucrat Sabri", 150);
        Bureaucrat huseyin("Bureaucrat Huseyin", 149);

        std::cout << huseyin << std::endl;
        huseyin.downGrade();
        std::cout << huseyin << std::endl;
        huseyin.upGrade();
        huseyin.upGrade();
        std::cout << huseyin << std::endl;
        huseyin.downGrade();
        huseyin.downGrade();
        huseyin.downGrade();
        std::cout << huseyin << std::endl;

        
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}