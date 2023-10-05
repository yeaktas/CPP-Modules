/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:09:49 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 07:12:58 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructors & Destructors
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {

	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm("ShrubberyCreationForm", 145, 137), _target(copy._target) {

	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
} 

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {

	std::cout << "ShrubberyCreationForm copy assigment operator called." << std::endl;
	if(this != &copy)
	{
		this->_signed = copy.getSign();
	}
	return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	if(this->getSign() == false)
		throw(AForm::AFormNotSigned());
	if(this->getExecuteGrade() < executor.getGrade())
		throw(AForm::GradeTooLowException());

	std::string fileName = this->_target + "_shrubbery";

	std::ofstream file(fileName);

	file << "	 oxoxoo    ooxoo   " << std::endl;
	file << "  ooxoxo oo  oxoxooo  " << std::endl;
	file << " oooo xxoxoo ooo ooox " << std::endl;
	file << " oxo o oxoxo  xoxxoxo " << std::endl;
	file << "  oxo xooxoooo o ooo  " << std::endl;
	file << "    ooo\\oo\\  /o/o     " << std::endl;
	file << "        \\  \\/ /       " << std::endl;
	file << "         |   /        " << std::endl;
	file << "         |  |         " << std::endl;
	file << "         | S|         " << std::endl;
	file << "         |  |         " << std::endl;
	file << "         |  |         " << std::endl;
	file << "  ______/____\\____    " << std::endl;
	file.close();
}
