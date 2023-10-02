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

#include "Form.hpp"

/*
    Subject açıklaması:

    Artik bürokrotlara sahip olduğumuza göre, onlara yapacak bir şeyler verelim.
    Bir yığın form doldurmaktan daha iyi bir aktivite olabilir mi?

    Form class'ını oluşturun.

    Form sınıfı şunları içermektedir:
    • A constant name.
        const name oluşturun.
    • A boolean indicating whether it is signed (at construction, it’s not)
        Formun imzalanıp imzalanmadığını gösteren bir bool değişkeni (constructor'da false, yani imzalanmamış olarak tanımlanmalıdır).
        bool _signed;
    • A constant grade required to sign it
        Formu imzalama yetkisinin belirlenmesi için gerekli yetki seviyesi.
        const int _signGrade;
    • And a constant grade required to execute it
        Formu yürütmek için geçerli yetki seviyesi.
        const int _executeGrade;

    Tüm öznitelikler private(özel) olacaktır, proctected değil. 
    Bu şekilde belirtmesinin nedeni, Form class'nın ilerleyen subjectlerde base class olacağından dolayıdır.

    Formun grade(seviye, erişim, izin) yapısı, Bürokratlar için geçerli olan kuralların aynısını takip eder.
	Bu nedenle bir formun notu sınırlar dışındaysa aşağıdaki istisnalar atılacaktır:
	Form::GradeTooHighException and Form::GradeTooLowException.

    Form sınıfı için, istenilen bilgileri ekrana yazdırmak için "insertion (<<) operator"unu aşırı yükleyin. 
    Bu, bir formun bilgilerini görüntülemek için kullanılacaktır.

    Parametre olarak Bürokrat alan Forma ayrıca bir "beSigned()" üye işlevi ekleyin.
	Bürokratın grade(not, seviye) yeterince yüksekse (gerekli olandan fazla veya eşit) form durumunu imzalı olarak değiştirir.

	Unutmayın; 1.derece 2.dereceden daha yüksektir. Not çok düşükse bir "Form::GradeTooLowException" atın.

	Son olarak, Bürokrat'a bir "signForm()" üye işlevi ekleyin. Form imzalandıysa şöyle bir çıktı verecektir.
	    <bureaucrat> signed <form>
	Aksi taktirde, şöyle bir şey yazdıracaktır.
	    <bureaucrat> could'nt sign <form> because <reason>
	Her şeyin beklendiği gibi çalıştığından emin olmak için bazı testler uygulayın ve teslim edin.

*/

int main ( void ) {

    try
    {
        Bureaucrat hamdi("Bureaucrat Hamdi", 100);
        std::cout << hamdi << std::endl;

        Form Form1("Form 1", 120, 75);
        std::cout << Form1 << std::endl;

        hamdi.signForm(Form1);
        std::cout << Form1 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}