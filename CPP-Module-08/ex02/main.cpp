/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:41:48 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/20 17:10:35 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

/*
	Subject açıklama:
	Bu görev, C++ STL'nin "std::stack" veri yapısının eksik bir özelliğini gidermeyi amaçlıyor. 
	"std::stack", STL konteynerlerinin bir örneği olmasına rağmen, kendisi doğrudan erişilebilir (iterable) değildir. 
	Görev, bu eksikliği gidermek için "MutantStack" adlı yeni bir sınıf oluşturmanızı istiyor. Bu sınıf, içinde bir "std::stack" veri yapısını 
	kullanarak std::stack'teki tüm üye işlevleri ve ayrıca yineleyicileri (iterators) sunmalıdır.

	İşte görevin ana gereksinimleri:
	
	"MutantStack" adlı bir C++ sınıfı oluşturun.
	
	Bu sınıf, "std::stack" veri yapısını kullanarak uygulanmalıdır.
	
	Sınıf, "std::stack" sınıfının tüm üye işlevlerini içermelidir.
	
	Ek olarak, "MutantStack" sınıfı, yineleyiciler (iterators) eklemelidir. Bu, "std::stack" üzerinde yineleme yapmanızı sağlar.
	
*/

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}