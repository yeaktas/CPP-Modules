/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:20:06 by yaktas            #+#    #+#             */
/*   Updated: 2023/08/17 08:20:06 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
    Subject açıklaması:

    Bürokrat class'ını oluşturun. (Bureaucrat)

    Bürokrat sınıfı şunları içermektedir:
    • A constant name.
        const name oluşturun. 
    • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
        Not, 1 ile 150 arasında olmalıdır ve geçersiz bir not kullanılmaya çalışıldığında istisna fırlatılmalıdır. 
        (Bureaucrat::GradeTooHighException veya Bureaucrat::GradeTooLowException).

    getName() ve getGrade() adlı iki özellik için get işlevleri sağlamalısınız. 
    getName(), Bürokrat'ın ismini döndüren bir işlev olmalıdır ve getGrade(), Bürokrat'ın notunu döndüren bir işlev olmalıdır.

    Ayrıca, Bürokrat'ın notunu artırabileceğiniz incrementGrade() ve azaltabileceğiniz decrementGrade() adlı iki üye işlevi 
    uygulamanız gerekmektedir. Ancak bu işlevler notun belirli sınırlar içinde olup olmadığını kontrol etmelidir. 
    Notun geçerli aralıkta olmadığı durumda, bu işlevler aynı istisnaları fırlatmalıdır ki bu da 
    Bureaucrat::GradeTooHighException veya Bureaucrat::GradeTooLowException istisnasıdır.

    Örnek olarak, bir Bürokrat'ın notu "3" ise, not artırma işlemi sonucunda notu "2" olmalıdır. 
    Bu nedenle, not artırma işlevi Bürokrat'ın notunu bir azaltma işlemi olarak düşünülmelidir.

    Atılan istisnaların try ve catch blokları kullanılarak yakalanabilir olması gerekir:

        try
        {
        //do some stuff with bureaucrats
        }
        catch (std::exception & e)
        {
        // handle exception
        }
    
    (<<) operatörü ile bir şeyler yazdırmak için aşırı yükleme uygulayacaksınız.
		<name>, bureaucrat grade <grade>.

*/

int main ( void ) {

    {
        std::cout <<"\033[0;31m" "---------------- Try-Catch Example [1] ----------------" "\033[m"<< std::endl;
        int x = -1;        
        std::cout << "Before try \n";
        try {
            std::cout << "Inside try \n";
            if (x < 0)
            {
                throw x;
                std::cout << "After throw (Never executed) \n";
            }
        }
        catch (int x ) {
            std::cout << "Exception Caught \n";
        }       
        std::cout << "After catch (Will be executed) \n";
    }

    {
        std::cout <<"\033[0;31m" "---------------- Try-Catch Example [2] ----------------" "\033[m"<< std::endl;
        try  {
           throw 10;
        }
        catch (char *excp)  {
            std::cout << "Caught " << excp;
        }
        catch (...)  {
            std::cout << "Default Exception\n";
        }
    }

	{
		std::cout <<"\033[0;31m" "---------------- No Exception Example [3] ----------------" "\033[m"<< std::endl;
		try
		{
			Bureaucrat huseyin("Bureaucrat Huseyin", 42);
			std::cout << huseyin << std::endl;
		}
		catch(const std::exception &e) // sadece std istisnalarını yakalar
		{
			std::cerr << e.what() << std::endl;
		}
	}

    {
		std::cout <<"\033[0;31m" "---------------- Too High Grade Example [4] ----------------" "\033[m"<< std::endl;
		try
		{
			Bureaucrat hamdi("Bureaucrat Hamdi", 151);
			std::cout << hamdi << std::endl;
		}
		catch(const std::exception &e) // sadece std istisnalarını yakalar
		{
			std::cerr << e.what() << std::endl;
        }
	}

    {
        std::cout <<"\033[0;31m" "---------------- Example [5] ----------------" "\033[m"<< std::endl;
        try
        {

            Bureaucrat hamdi("Bureaucrat Hamdi", 140);
            Bureaucrat sabri("Bureaucrat Sabri", 150);
            Bureaucrat huseyin("Bureaucrat Huseyin", 149);

            std::cout << huseyin << std::endl;
            huseyin.downGrade();
            std::cout << huseyin << std::endl;
            huseyin.upGrade();
            huseyin.upGrade();
            std::cout << huseyin << std::endl;
            huseyin.downGrade();
            huseyin.downGrade();
            huseyin.downGrade();
            std::cout << huseyin << std::endl;

        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}