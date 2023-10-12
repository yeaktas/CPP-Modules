/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:52:34 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 16:56:41 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void print(T a)
{
	std::cout << a << " ";
}

template<typename T, typename Function>
void iter(T arr, int len, Function func)
{
	for(int i = 0; i < len; i++)
	{
		func(arr[i]);
	}	
}

#endif