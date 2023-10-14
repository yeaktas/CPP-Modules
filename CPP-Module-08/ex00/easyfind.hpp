/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 04:14:53 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/14 04:14:53 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

/* template<typename T> int easyfind(T cont, int n)
{
	for (int i = 0; i < (int)cont.size(); i++)
	{
		if(cont[i] == n)
		{
			std::cout << "Finded! " << n;
			return cont[i];
		}
	}
	std::cout << "Not finded! " << n;  
	throw (n);
	return (NULL);
}  */

template<typename T> int easyfind(T cont, int n)
{

	if (std::find(cont.begin(), cont.end(), n) != cont.end())
	{
		std::cout << "Finded! " << n << std::endl;
		return n;
	}
	throw (n);
	return (0);
}  

#endif