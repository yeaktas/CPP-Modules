/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:49:28 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 06:23:55 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:  
		const std::string _target;
	
	public:
		//Constructors & Destructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		void execute(Bureaucrat const &executor) const;
};

#endif