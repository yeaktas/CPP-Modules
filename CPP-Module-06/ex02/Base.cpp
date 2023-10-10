/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:20:52 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/10 16:20:53 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base	*Base::generate(void)
{
	srand(time(0));
	int randomNbr = rand() % 3;
	if (randomNbr == 0)
		return (new A());
	else if (randomNbr == 1)
		return (new B());
	return (new C());
}

void Base::identify(Base &p) {
    try {
        Base a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } catch (std::bad_cast &) {
    }
    
    try {
        Base b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    } catch (std::bad_cast &) {
    }
    
    try {
        Base c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    } catch (std::bad_cast &) {
    }
}

void Base::identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}
