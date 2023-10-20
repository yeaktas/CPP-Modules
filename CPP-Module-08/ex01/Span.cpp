/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:55:48 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/20 18:21:29 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {

	std::cout << "Default constructor called." << std::endl;
}

Span::Span(unsigned int N) : _n(N) {

	std::cout << "Construcor called." << std::endl;
}

Span::Span(const Span &ref) {
	
	std::cout << "Copy constructor called." << std::endl;
	*this = ref;
}

Span::~Span() {

	std::cout << "Destructor called." << std::endl;
}

Span &Span::operator=(const Span &ref){

	std::cout << "Copy assigment operator called." << std::endl;
	if(this != &ref)
	{
		this->_list = ref._list;
		this->_n = ref._n;
	}
	return (*this);
}

void Span::addNumber(unsigned int N) {
	
	if(this->_list.size() >= this->_n)
		throw(ListIsFull());
	this->_list.push_back(N);
}

void Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if ((unsigned long)std::distance(begin, end) > this->_n - this->_list.size())
		throw (std::runtime_error("Other list size is to low!") );
	this->_list.insert(this->_list.end(), begin, end);
}

unsigned int Span::longestSpan(void) {
	
	if(_list.size() < 2)
		throw std::runtime_error("Not enouhgh numbers to calculate longest span.");
	int min = *std::min_element(_list.begin(), _list.end());
	int max = *std::max_element(_list.begin(), _list.end());

	return max - min;
}

unsigned int Span::shortestSpan(void) {

	int	min = longestSpan();
	if (this->_list.size() < 2)
		throw(std::runtime_error("List arguments is to low!"));
	else
	{
		std::list<int>::iterator it1 = this->_list.begin();
		std::list<int>::iterator it2 = this->_list.end();
		while (it1 != this->_list.end())
		{
			it2 = this->_list.begin();
			while (it2 != this->_list.end())
			{
				if (it1 != it2)
				{
					if (std::abs(*it1 - *it2) < min)
					{
						min = std::abs(*it1 - *it2);
					}
				}
				it2++;
			}
			it1++;
		}
	}
	return(min);
}

const char* Span::ListIsFull::what() const throw(){
	return ("List is Full!");
}