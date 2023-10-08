/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:03:23 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/08 05:46:15 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/* 
	Subject Açıklama:

	Verilen görev, bir C++ ifadesinin string temsilini alan ve bu ifadenin en yaygın olan dört
	skalardan birine dönüştüren bir ScalarConverter adında bir statik sınıfın oluşturulmasını istiyor. 
	Bu skalalar şunlardır:

	char
	int
	float
	double
	Char parametreleri için, yalnızca ondalık gösterim kullanılacaktır. 
	Geçerli olmayan karakterler, char'a dönüştürülürken kullanılmamalıdır. 
	Eğer bir char dönüşümü geçerli değilse, bilgilendirici bir mesaj yazdırılmalıdır.
	
	Örnekler:
	
	Char literals (Karakter ifadeleri): 'c', 'a', ...
	Int literals (Tamsayı ifadeleri): 0, -42, 42...
	Float literals (Ondalık sayı ifadeleri): 0.0f, -4.2f, 4.2f...
	Pseudo literals for float (Float için sahte ifadeler): -inff, +inff, nanf
	Double literals (Ondalık sayı ifadeleri): 0.0, -4.2, 4.2...
	Pseudo literals for double (Double için sahte ifadeler): -inf, +inf, nan
	
	Bu görev, verilen string ifadeyi doğru türde bir skalara dönüştürmekle ilgilidir ve geçerli olmayan 
	veya dönüştürülemeyen ifadeler için uyarılar içermelidir. Örneğin, bir kullanıcı "abcd" gibi bir 
	stringi geçerli bir char ifadesine dönüştürmeye çalışırsa, program bu işlemi yapamayacağını ve 
	bunun yerine bir uyarı mesajı gösterecektir.
 */

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return (0);
	}
	std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;

	return (1);
}