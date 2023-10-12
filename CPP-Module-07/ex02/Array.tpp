/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:21:01 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/12 17:35:14 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T >
Array<T>::Array() : _array(NULL), _size(0){
	std::cout << "Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){
	std::cout << "Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &ref) : _array(new T[ref._size]), _size(ref._size){
	std::cout << "Copy Constructor Called" << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = ref._array[i];
}

template<typename T>
Array<T>::~Array( void ){
	std::cout << "Destructor Called" << std::endl;
	delete[] _array;
}

template< typename T >
Array<T> &Array<T>::operator=( const Array &ref ){
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		delete[] this->_array;
		this->_array = new T[ref._size];
		this->_size = ref._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = ref._array[i];
	}
	return (*this);
}

template< typename T >
T &Array<T>::operator[](unsigned int i) const{
	if (i >= this->_size)
		throw (OutOfBoundsException());
	return (this->_array[i]);
}

template<typename T>
unsigned int Array<T>::size(void){
	return (this->_size);
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw(){
	return ("Index is out of bounds!");
}

#endif

