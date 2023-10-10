/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:20:57 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 16:20:58 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
    public:
        virtual ~Base();
        static Base *generate(void);
        static void identify(Base *p);
        static void identify(Base &p);
};

#endif