/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:12:59 by yaktas            #+#    #+#             */
/*   Updated: 2023/08/17 08:12:59 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName(void) const; //Bir veri değiştirmediği için const kullandık.
        int getGrade(void) const;

        void upGrade(void);
        void downGrade(void);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif