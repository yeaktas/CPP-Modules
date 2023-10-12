/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:00:09 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 17:36:23 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array{

	private:
		T *_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int);
		Array(const Array &ref);
		~Array();

		Array &operator=(const Array &ref);
		T &operator[](unsigned int i) const;

		unsigned int size(void);

		class OutOfBoundsException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif

