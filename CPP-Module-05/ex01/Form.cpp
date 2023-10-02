/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:17:41 by yaktas            #+#    #+#             */
/*   Updated: 2023/08/23 20:17:41 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors & Destructors
Form::Form(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {

    std::cout << "Form default constucter called." << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {

    std::cout << "Form constucter called." << std::endl;
    this->_signed = false;
    if(signGrade < 1 || executeGrade < 1)
        throw(Form::GradeTooHighException());
    if(signGrade > 150 || executeGrade > 150)
        throw(Form::GradeTooLowException());
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {

    std::cout << "Form copy constructer called." << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &copy) {

    std::cout << "From copy assigment operator called." << std::endl;
    if(this != &copy)
        this->_signed = copy.getSign();
    return (*this);
}

Form::~Form( void ) {

    std::cout << "Form destructor called." << std::endl;
}

//Getters
std::string Form::getName() const {

    return (this->_name);
}
bool Form::getSign() const {

    return (this->_signed);
}
int Form::getSignGrade() const {

    return (this->_signGrade);
}
int Form::getExecuteGrade() const {

    return (this->_executeGrade);
}

//Member Functions
void Form::beSigned(const Bureaucrat &bureaucrat) {

    if(this->_signGrade >= bureaucrat.getGrade())
        this->_signed = true;
    else
        throw(Form::GradeTooLowException());
}

//Exceptions
const char *Form::GradeTooHighException::what( void ) const throw() {

    return ("Grade too HIGH.");
}
const char *Form::GradeTooLowException::what( void ) const throw() {

    return ("Grade too LOW.");
}

std::ostream &operator<<(std::ostream &os, const Form &f) {

    os << "[Form Name: " << f.getName() << "] - [Sign Grade: " << f.getSignGrade() << "] - [Execute Grade: " << f.getExecuteGrade() << "] - [Sign Status: " << f.getSign() << "]";
    return (os);
}