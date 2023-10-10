/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:34 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 14:53:35 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialize
{
    private:
        std::string se;
    public:
        Serialize();
        ~Serialize();
        Serialize(Serialize const &src);
        Serialize &operator=(Serialize const &src);
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif