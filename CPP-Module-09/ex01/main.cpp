/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:30 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:42:20 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
    Subject açıklama:

    Bu görev, ters Polonezya notasyonlu (RPN) matematiksel ifadeleri işleyen bir program oluşturmanızı istiyor. 
    İşte belirtilen gereksinimlere göre programınızın çalışması için yapmanız gerekenleri anlatan bir açıklama:

    Program Adı: RPN
    
    Programınızın adını "RPN" olarak belirtmelisiniz.
    
    Giriş Argümanı:
    Programınız, ters Polonezya matematiksel ifadesini bir argüman olarak almalıdır. 
    Yani kullanıcı, programı çalıştırırken bir RPN ifadesini komut satırından girmelidir.
    
    Kısıtlar:
    İfade içinde kullanılan sayılar her zaman 10'dan küçük olacaktır. 
    Ancak bu sınırlama yalnızca girdi olarak kullanılan sayıları etkiler, hesaplamanın kendisi ve sonuç bu kurala uymaz.
    
    Programın İşlevi:
    Programınız, verilen RPN ifadesini işlemeli ve doğru sonucu standart çıktı üzerinde görüntülemelidir. 
    İşlem başarısız olursa, hata mesajı standart çıktıda görüntülenmelidir.
    
    İşlem Türleri:
    Programınız, aşağıdaki işlem türlerini desteklemelidir: Toplama (+), Çıkarma (-), Bölme (/), Çarpma (*).
    
    Konteyner Kullanımı:
    Programınızın kodunda en az bir konteyner kullanmalısınız. 
    Bu, verileri geçici olarak saklamak veya işlem yapmak için kullanabileceğiniz bir veri yapısı veya koleksiyon olabilir.
    
    Programınız parantezleri veya ondalık sayıları ele almaya gerek duymaz.
*/

int main(int ac, char* av[]) {
    if(ac != 2) {
        std::cerr << "Usage: " << av[0] << " expression" << std::endl;
        return(1);
    }
    RPN rpn;
    try {
        double result = rpn.evaluate(av[1]);
        std::cout << result << std::endl;
    } catch (MyExc e) {
        std::cout << e.what();
    }
    return 0;
}