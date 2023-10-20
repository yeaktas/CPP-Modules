/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:35:01 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/15 22:35:01 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
    Subject açıklama:

    Bu görev, bir C++ sınıfı olan "Span" sınıfını oluşturmanızı istiyor. Bu sınıf, maksimum N tam sayıyı saklayabilen bir sınıf olacak. 
    N, "unsigned int" türünde bir değişken olacak ve yapıcı fonksiyona tek parametre olarak iletiliyor. Sınıfın bu temel özellikleri ve işlevleri olacak:

        •   Bir "Span" sınıfı oluşturun ve bu sınıfın yapıcı fonksiyonu, N değerini alarak sınıfın boyutunu belirler. 
            Eğer N değerinden fazla sayı eklemeye çalışılırsa bir istisna fırlatmalıdır.
    
        •   "addNumber" adlı bir üye fonksiyon ekleyin. Bu fonksiyon, bir tek sayıyı "Span" sınıfına eklemek için kullanılacak. 
            Eğer sınıfın kapasitesi dolduysa, bir istisna fırlatmalıdır.
    
        •   "shortestSpan" ve "longestSpan" adlı iki üye fonksiyon ekleyin. 
            Bu fonksiyonlar, saklanan sayılar arasındaki en kısa veya en uzun mesafeyi bulacak ve bu mesafeyi döndürecek. 
            Eğer sınıfta hiç sayı yoksa veya yalnızca bir sayı varsa, bir istisna fırlatmalıdır.
    
        •   "Span" sınıfını test etmek için kapsamlı testler yazın ve en az 10.000 sayı ekleyerek sınıfınızı test edin. 
            Daha fazla sayı eklemek sınıfınızın performansını daha iyi değerlendirmenize yardımcı olur.
    
        •   "Span" sınıfına bir dizi sayıyı tek bir çağrıyla eklemek için bir üye fonksiyon ekleyin. 
            Bu, tek tek "addNumber" çağrıları yapmak yerine daha verimli bir şekilde bir aralık (range) eklemenize olanak sağlar.
*/

int main(void) {

    {
        try{
            Span spa(6);
            spa.addNumber(5);

            std::list<int> list;

            list.push_back(1);
            list.push_back(10);
            list.push_back(3);

            spa.addNumber(list.begin(), list.end());

            std::cout << spa.longestSpan() << std::endl;
            std::cout << spa.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {
        try{
            Span bigDuck(10000);

            std::list<int> list(9999);
            
            std::srand(time(NULL));
            std::generate(list.begin(), list.end(), std::rand);
            bigDuck.addNumber(list.begin(), list.end());

            std::cout << bigDuck.longestSpan() << std::endl;
            std::cout << bigDuck.shortestSpan() << std::endl;

        }
        catch( std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}


