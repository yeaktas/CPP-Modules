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

#include "AForm.hpp"

//Constructors & Destructors
AForm::AForm(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {

    std::cout << "AForm default constucter called." << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {

    std::cout << "AForm constucter called." << std::endl;
    this->_signed = false;
    if(signGrade < 1 || executeGrade < 1)
        throw(AForm::GradeTooHighException());
    if(signGrade > 150 || executeGrade > 150)
        throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {

    std::cout << "AForm copy constructer called." << std::endl;
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy) {

    std::cout << "From copy assigment operator called." << std::endl;
    if(this != &copy)
        this->_signed = copy.getSign();
    return (*this);
}

AForm::~AForm( void ) {

    std::cout << "AForm destructor called." << std::endl;
}

//Getters
std::string AForm::getName() const {

    return (this->_name);
}
bool AForm::getSign() const {

    return (this->_signed);
}
int AForm::getSignGrade() const {

    return (this->_signGrade);
}
int AForm::getExecuteGrade() const {

    return (this->_executeGrade);
}

//Member Functions
void AForm::beSigned(const Bureaucrat &bureaucrat) {

    if(bureaucrat.getGrade() > this->getSignGrade())
        throw(AForm::GradeTooLowException());
    if(this->_signed == true)
        throw(AForm::AFormAlreadySigned());
    this->_signed = true;
}

//Exceptions
const char *AForm::GradeTooHighException::what( void ) const throw() {

    return ("Grade too HIGH.");
}
const char *AForm::GradeTooLowException::what( void ) const throw() {

    return ("Grade too LOW.");
}

const char *AForm::AFormAlreadySigned::what( void ) const throw() {

    return ("AForm already signed.");
}

const char *AForm::AFormNotSigned::what( void ) const throw() {

    return ("AForm not signed.");
}


std::ostream &operator<<(std::ostream &os, const AForm &f) {

    os << "[AForm Name: " << f.getName() << "] - [Sign Grade: " << f.getSignGrade() << "] - [Execute Grade: " << f.getExecuteGrade() << "] - [Sign Status: " << f.getSign() << "]";
    return (os);
}