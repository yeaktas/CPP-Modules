/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:37 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 14:53:38 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize(){}

Serialize::~Serialize(){}

Serialize::Serialize(Serialize const &src){
    *this = src;
}
Serialize &Serialize::operator=(Serialize const &src){
    this->se = src.se;
    return (*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}