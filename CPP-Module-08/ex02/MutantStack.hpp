/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:43:14 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/20 17:11:06 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	    typedef typename std::stack<T>::container_type::iterator iterator;
	
	    MutantStack() {}
	    ~MutantStack() {}
	    MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}
	    MutantStack<T> &operator=(const MutantStack<T> &copy)
	    {
	        std::stack<T>::operator=(copy);
	        return *this;
	    }
	
	    iterator begin() { 
			return std::stack<T>::c.begin(); 
		}
		
	    iterator end() { 
			return std::stack<T>::c.end(); 
		}
};

#endif