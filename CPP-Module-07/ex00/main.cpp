/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:06:20 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/11 22:06:20 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    Subject Açıklama: 

    Aşağıda verilen işlev şablonlarını oluşturmanız istenmektedir:

    • swap: Verilen iki argümanın değerlerini takas eder. Herhangi bir değer döndürmez.

    • min: Argümanlarının değerlerini karşılaştırır ve en küçüğünü döndürür. Eğer iki değer eşitse, ikinciyi döndürür.

    • max: Argümanlarının değerlerini karşılaştırır ve en büyüğünü döndürür. Eğer iki değer eşitse, ikinciyi döndürür.

    Bu işlevler, herhangi bir türde argümanlarla çağrılabilir olmalıdır. Tek gereklilik, iki argümanın aynı türe sahip olması ve 
    karşılaştırma operatörlerini desteklemesi gerektiğidir. Bu şablon işlevleri başlık dosyalarında tanımlanmalıdır.

*/

#include "Whatever.hpp"

int main( void ) {

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}
