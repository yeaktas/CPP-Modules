/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:53:29 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/20 16:43:54 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>


class Span {
	
	private:
		std::list<int> _list;
		unsigned int _n;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &ref);
		~Span();

		Span &operator=(const Span &ref);
		
		void addNumber(unsigned int N);
		void addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
		unsigned int longestSpan(void);
		unsigned int shortestSpan(void);
		
		class ListIsFull : public std::exception{
			public:
				virtual const char *what() const throw();
		};

};

#endif