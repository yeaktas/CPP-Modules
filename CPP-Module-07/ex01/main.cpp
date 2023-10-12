/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:56:49 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 16:58:45 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

/* 
	Subject açıklama:


	Bu görevde, iter adlı bir işlev şablonu oluşturmanız isteniyor. Bu işlev şablonu üç parametre almalı ve bir şey döndürmemelidir. İşte bu işlevin ayrıntıları:
	İlk parametre, bir dizinin adresini almalıdır.
	İkinci parametre, dizinin uzunluğunu belirtmelidir.
	Üçüncü parametre, dizinin her elemanı üzerinde çağrılacak bir işlev olmalıdır.
	Bu işlev şablonunun herhangi bir veri türünden dizilerle çalışabilmesi gerekiyor. Üçüncü parametre, bir işlev şablonu örneği olabilir.
*/

int main()
{
	std::string array1[] = {"lutfi", "ergun", "sen"};
	int len1 = sizeof(array1) / sizeof(array1[0]);

	char array2[] = {'l', 'e', 's'};
	int len2 = sizeof(array2) / sizeof(array2[0]);

	int array3[] = {4, 8, 15, 16, 23, 42};
	int len3 = sizeof(array3) / sizeof(array3[0]);
	
	std::cout << "Array 1 = ";
	::iter(array1, len1, print<std::string>);
	std::cout << std::endl;

	std::cout << "Array 2 = ";
	::iter(array2, len2, print<char>);
	std::cout << std::endl;

	std::cout << "Array 3 = ";
	::iter(array3, len3, print<int>);
	std::cout << std::endl;	
}