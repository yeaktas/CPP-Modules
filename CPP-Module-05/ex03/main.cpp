/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:41:27 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 22:56:53 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/* 
	Subject açıklama:
		Bu görevde "Stajyer" sınıfını uygulamanız isteniyor. Stajyer sınıfının adı, notu veya özel özellikleri yoktur. 
		Bürokratların tek ilgilendiği şey, işlerini yapmalarıdır. Ancak stajyerin önemli bir yeteneği vardır:

	makeForm() işlevi:
		İki dize alır. İlk dize, bir formun adını, ikinci dize ise formun hedefini temsil eder.
		Bu işlev, parametre olarak verilen ad ile başlatılan bir Form nesnesine bir işaretçi döndürür ve bu formun hedefini 
		ikinci parametre olarak belirler. İşlem tamamlandığında aşağıdaki gibi bir çıktı vermelidir:
		Intern creates <form>
		Eğer parametre olarak verilen form adı mevcut değilse, açık bir hata mesajı vermelisiniz.

	Önemli olan, kodunuzu karmaşık ve okunaksız bir yapıya dönüştürmeyecek, gereksiz if-else ağaçları gibi çirkin çözümlerden kaçınmanızdır. 
	Bu görevde istenen şey, kodunuzu temiz ve anlaşılır tutmanızdır. Ayrıca, kodunuzun doğru çalıştığını test etmelisiniz.

	Örnek olarak, aşağıdaki kod "RobotomyRequestForm" adlı bir formun "Bender" hedefine yönelik olarak oluşturulmasını sağlar.
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}

*/

int main(void) {

	try
	{

		Bureaucrat yufus("Yufus", 3);
		Intern intern;

		AForm *aform;

		aform = intern.makeForm("robotomy request", "robot");
		std::cout << *aform << std::endl;

		yufus.signForm(*aform);
		std::cout << *aform << std::endl;

		yufus.executeForm(*aform);
		std::cout << *aform << std::endl;

		delete aform;

	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}