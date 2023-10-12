/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:59:57 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 18:12:21 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

/*
    Subject açıklama:

    Bu görevde size bir şablon sınıf olan Array oluşturmanızı istiyor. Bu sınıf, şu davranışları ve işlevleri uygulamalıdır:
    
    • Parametresiz kurucu fonksiyon: Boş bir dizi oluşturmalıdır.
    • Bir tamsayı (unsigned int) n parametresi ile kurucu fonksiyon: Varsayılan olarak başlatılmış n eleman içeren bir dizi oluşturmalıdır.
    • Kopyalama ve atama operatörü ile kurucu fonksiyonlar: Hem orijinal diziyi hem de kopyasını değiştirme sonucu, diğer diziyi etkilememelidir.
    • Bellek tahsisi için new[] operatörünü kullanmalısınız. Önleyici tahsis (bellek tahsisini önceden yapma) yasaktır ve programınız asla tahsis edilmemiş belleğe erişmemelidir.
    • Elemanlara köşeli parantez ([]) operatörü ile erişilebilmelidir.
    • Köşeli parantez operatörü ile bir elemana erişirken, elemanın dizinin sınırları dışında bir indekse sahipse, bir std::exception istisnası fırlatılmalıdır.
    • size() adlı bir üye işlev, dizideki eleman sayısını döndürmelidir. Bu üye işlev parametre almadığı gibi mevcut örneği değiştirmemelidir.
    
    Ayrıca, bu sınıfın işlevlerini test etmek için main.cpp adlı bir dosya içinde testler yapmanız gerekmektedir.
    Bu testler, sınıfın beklenen davranışlarını ve işlevlerini doğru bir şekilde uygulayıp uygulamadığını kontrol etmek için kullanılacaktır.
    
    Özetle, size Array adlı bir şablon sınıf oluşturup, belirtilen işlevselliği uygulayarak, bellek yönetimi ve 
    dizi işlemleri dahil olmak üzere verilen gereksinimleri karşılayan bir C++ sınıfı oluşturmanız isteniyor.
*/

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}