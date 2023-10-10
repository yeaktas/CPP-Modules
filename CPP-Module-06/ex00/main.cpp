/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 05:03:23 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 11:55:13 by yaktas           ###   ########.fr       */
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

bool	is_valid(std::string &s){
	if (ScalarConverter::is_it_for_science(s))
		return (true);
	if (s.length() == 1 && isalpha(s[0])){
		s =  std::to_string(static_cast<int>(s[0]));
		return (true);
	}
	if (ScalarConverter::is_wrong_number(s))
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Bad number of args" << std::endl;
		return (0);
	}
	std::string str = (std::string)av[1];
	if (is_valid(str))
		ScalarConverter::convert(str);
	else
		std::cout << "Invalid" << std::endl;
}