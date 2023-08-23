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

#include "From.hpp"

//Constructors & Destructors
Form::Form(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {

    std::cout << "Form default constucter called." << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {

    std::cout << "Form constucter called." << std::endl;
    this->_signed = false;
    if(signGrade < 1 || executeGrade < 1)
        throw(Form::GradeTooHighException);
    if(signGrade > 150 || executeGrade > 150)
        throw(Form::GradeTooLowException);
}

Form::Form(const Form& copy){

    std::cout << "Form copy constructer called." << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &copy) {

    std::cout << "From copy assigment operator called." << std::endl;
    return (*this);

    //need control.
}

Form::~Form( void ) {

    std::cout << "Form destructor called." << std::endl;
}

//Getters
std::string getName() const {
    
    return (this->_name);
}
bool getSign() const {

    return (this->_signed);
}
int getSignGrade() const {

    return (this->_signGrade);
}
int getExecuteGrade() const {

    return (this->_executeGrade);
}

//Member Functions
void From::beSigned(const Bureaucrat &bureaucrat) {

    if(this->_signGrade >= bureaucrat.getGrade())
        this->_signed = true;
    else
        throw(Form::GradeTooLowException)
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {

    return ("Grade too HIGH.");
}
const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {

    return ("Grade too LOW.");
}

