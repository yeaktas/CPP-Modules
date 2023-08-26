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

#include "Form.hpp"

int main ( void ) {

    try
    {
        Bureaucrat hamdi("Bureaucrat Hamdi", 150);
        std::cout << hamdi << std::endl;

        Form Form1("Form 1", 100, 75);
        std::cout << Form1 << std::endl;

        hamdi.signForm(Form1);
        std::cout << Form1 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}