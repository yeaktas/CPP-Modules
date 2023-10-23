/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:45:26 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:59:59 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
    Subject açıklama:

    Bu görev, "PmergeMe" adında bir program geliştirmenizi istiyor ve bu programın aşağıdaki özelliklere sahip olmasını bekliyor:

    •Pozitif bir tamsayı dizisi alabilen bir program olmalıdır.
    •Pozitif tamsayı dizisini sıralamak için birleştirme eklemeli sıralama (merge-insert sort) algoritmasını kullanmalıdır. 
        Ayrıca, bu sıralama işlemi için Ford-Johnson algoritmasını kullanmanız gerekmektedir.
    •Programın çalışması sırasında bir hata oluşursa, standart çıktı üzerinde bir hata mesajı görüntülenmelidir.
    •Program, en az iki farklı veri yapısını kullanmalıdır ve bu veri yapısı en az 3000 farklı tamsayıyı işleyebilmelidir.
    
    Programınızın standart çıktıda görüntülemesi gereken bilgiler şunlar:

    • İlk satırda, açık bir metin ve sıralanmamış pozitif tamsayı dizisi görüntülenmelidir.
    • İkinci satırda, açık bir metin ve sıralanmış pozitif tamsayı dizisi görüntülenmelidir.
    • Üçüncü satırda, programınızın sıralama işlemi için kullandığı ilk veri yapısını kullanarak geçen zamanı 
        gösteren bir açık metin ve zaman bilgisi görüntülenmelidir.
    • Son satırda, programınızın sıralama işlemi için kullandığı ikinci veri yapısını kullanarak geçen zamanı 
        gösteren bir açık metin ve zaman bilgisi görüntülenmelidir.
    • Ayrıca, zaman bilgisinin belirli bir formatı olmamakla birlikte, farklı veri yapıları arasındaki zaman 
        farkını açıkça gösterebilecek bir hassasiyetle gösterilmesi gerekmektedir.

*/

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Give me more numbers" << std::endl;
        return(1);
    }
    PmergeMe a(ac, av);
    a.Info_begin(0);
    a.mergeVector();
    a.mergeDeque();
}