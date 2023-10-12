/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:24:36 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 01:24:36 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// Şablonda birden fazla tür alınabilir ve kullanılabilir, yeni eklenecek türün nasıl kullandıldığına göre değişir.
// typename hem classlar hem de diğer türler için kullanılabilir.

template<typename T> 
void swap( T& a, T& b ){
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min( T a, T b ){
	if(a > b)
		return (b);
	else if (a == b)
		return(b);
	else
		return(a);
}

template<typename T>
T max( T a, T b ){
	if(b > a)
		return (b);
	else if (a == b)
		return(b);
	else
		return(a);
}

#endif