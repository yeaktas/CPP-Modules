/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:17:47 by yaktas            #+#    #+#             */
/*   Updated: 2023/08/23 20:17:47 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {

    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;

    public:
        //Constructors & Destructors
        Form();
        Form(std:string name, int signGrade, int executeGrade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        //Getters
        std::string getName() const;
        bool        getSign() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;

        //Member Functions
        void beSigned(const Bureaucrat &bureaucrat);

        //Exceptions
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception{
		    public:
			    virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif