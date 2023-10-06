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

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {

    protected:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;

    public:
        //Constructors & Destructors
        AForm(); //default constuctor
        AForm(std::string name, int signGrade, int executeGrade); //constructor
        AForm(const AForm &copy); //copy constructor
        AForm &operator=(const AForm &copy); 
        virtual ~AForm();

        //Getters
        std::string getName() const;
        bool        getSign() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;

        //Member Functions
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0; // virtual pure method.

        //Exceptions
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception{
		    public:
			    virtual const char *what(void) const throw();
        };
        class AFormAlreadySigned : public std::exception{
            public:
                virtual const char *what(void) const throw();
        };
        class AFormNotSigned : public std::exception{
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif