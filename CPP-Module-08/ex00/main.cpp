/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 03:35:22 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/14 03:35:22 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
    Subject açıklama:

    Bu görev, C++ programlama dilinde bir işlev şablonu oluşturmanızı istiyor. Bu işlev, herhangi bir tür T'yi kabul eder ve iki parametre alır:

    İlk parametre, T türünden bir veri yapısı (container) olmalıdır.
    İkinci parametre ise bir tam sayı (integer) olmalıdır.
    Varsayılan olarak, T türünün bir tamsayıları içeren bir veri yapısı olduğu kabul edilmektedir. 
    İşlevin amacı, ikinci parametreyi (verilen tam sayıyı) birinci parametre içinde aramaktır. 
    Eğer ikinci parametreyi bulursa, işlev bu değeri döndürmelidir. Ancak eğer ikinci parametre verilen veri yapısında bulunmuyorsa, 
    işlev ya bir istisna fırlatabilir ya da tercihinize göre belirlediğiniz bir hata değerini döndürebilir.

    Bu görevdeki ilham kaynağı, standart C++ konteynerlerinin (vector, list, set, map, vb.) nasıl davrandığını incelemektir. 
    Bu işlevin işleyişini ve hata işlemi yöntemini kendi kodunuzda uygulamanız gerekiyor. 
    Son olarak, işlevin doğru bir şekilde çalıştığını doğrulamak için kendi testlerinizi oluşturup işlevi test etmelisiniz.

    Görev, C++ programlama dilinde temel işlevlerin nasıl oluşturulduğunu anlamanıza yardımcı olacak bir başlangıç görevidir.
*/

int main(void)
{
    try
    {
        std::vector <int> vec;
        std::list <int> list;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);

        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(4);
        list.push_back(5);
        list.push_back(6);
        easyfind(vec, 4);
        easyfind(list, 8);
    }
    catch(const int e)
    {
        std::cerr << "Not finded! " << e << std::endl;
    }
    
    
}