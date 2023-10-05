/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:49:25 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 06:39:33 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors & Destructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {

	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("RobotomyRequestForm", 72, 45), _target(copy._target) {

	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
} 

RobotomyRequestForm::~RobotomyRequestForm() {

	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {

	std::cout << "RobotomyRequestForm copy assigment operator called." << std::endl;
	if(this != &copy)
	{
		this->_signed = copy.getSign();
	}
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	if(this->getSign() == false)
		throw(AForm::AFormNotSigned());
	if(this->getExecuteGrade() < executor.getGrade())
		throw(AForm::GradeTooLowException());

	std::cout << "rrrrrrharrrrrharrrrrrrrrrharrrrrrrrhh" << std::endl;

	srand(time(NULL));
	int rnd = rand() % 2;

	if(rnd == 0)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}