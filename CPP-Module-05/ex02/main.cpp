/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:41:27 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/05 07:11:44 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* 
	Subject açıklama:

	Bu görev, bir abstract (soyut) sınıf olan "AForm" adlı temel bir sınıf oluşturmayı gerektiriyor. 
	Bu temel sınıfın özelliklerinin özel (private) olması ve tüm alt sınıflarda bu özelliklere erişiminin sınırlanması gerekiyor. 
	Ardından, aşağıdaki somut (concrete) sınıfları eklemeniz isteniyor:

	ShrubberyCreationForm: Gerekli notlar: imza 145, yürütme 137
	Bu sınıf, çalışma dizininde "<hedef>_shrubbery" adlı bir dosya oluşturmalı ve içine ASCII ağaçlar yazmalıdır.

	RobotomyRequestForm: Gerekli notlar: imza 72, yürütme 45
	Bu sınıf, matkap sesleri yapmalı ve ardından "<hedef>" isimli hedefin robotomize edildiğini (başarı oranı %50) veya başarısız olduğunu bildirmelidir.

	PresidentialPardonForm: Gerekli notlar: imza 25, yürütme 5
	Bu sınıf, "<hedef>" isimli hedefin Zaphod Beeblebrox tarafından affedildiğini bildirmelidir.

	Her bir sınıfın yapıcı metoduna yalnızca bir parametre alması gerekmektedir: formun hedefini belirten bir parametre, 
	örneğin "ev" şeklinde, evde çalı eklemek isterseniz.

	Ayrıca, temel form sınıfına "execute(Bureaucrat const & executor) const" adlı bir üye fonksiyon eklemeniz ve 
	bu fonksiyonun somut sınıfların işlemini gerçekleştiren bir işlevi çağırmanız gerekmektedir. 
	Bu işlem sırasında formun imzalandığını ve formu yürütmeye çalışan bürokratın yeterli düzeyde not aldığını kontrol etmelisiniz. 
	Aksi takdirde uygun bir istisna (exception) fırlatmalısınız. 
	İhtiyaca bağlı olarak bu gereksinimleri her somut sınıfta veya temel sınıfta kontrol etmek ve işlemi gerçekleştirmek isteyebilirsiniz.

	Son olarak, Bureaucrat sınıfına "executeForm(Form const & form)" adlı bir üye fonksiyon eklemelisiniz. 
	Bu fonksiyon, formu yürütmeye çalışmalıdır. Başarılı bir şekilde yürütülürse, "<bürokrat> <form'u> yürüttü" gibi bir çıktı vermelidir. 
	Başarısız olursa açık bir hata mesajı vermelidir. Tüm bu işlemleri test ederek her şeyin beklenildiği gibi çalıştığından emin olmalısınız.
	<bureaucrat> executed <form>

*/

int main() {

	try
	{

	Bureaucrat emre("Emre", 4);
	std::cout << emre << std::endl;

	ShrubberyCreationForm FormS("shrubberyyyyyyyyy");
	std::cout << FormS << std::endl;

	emre.signForm(FormS);

	std::cout << FormS << std::endl;

	emre.executeForm(FormS);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}