/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 07:32:12 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 17:27:04 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		//Constructors & Destructors
		Intern();
		Intern(const Intern &copy);
		~Intern();
		
		Intern &operator=(const Intern &copy);

		AForm *makeForm(std::string formName, std::string targetName);

		/* Exceptions */
		class InternCantCreatedForm : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};
};

#endif