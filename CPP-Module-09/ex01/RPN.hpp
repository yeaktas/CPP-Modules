/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:38 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:40:39 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
        std::stack<double> _stack;

    public:
        RPN();
        ~RPN();
        RPN(const RPN &r);
        RPN& operator=(const RPN &r);
        
        double evaluate(const std::string& expr);

};

class MyExc : public std::exception {
    private:
        const char * msg;
    public:
    MyExc(const char *msg) : msg(msg) {}
    const char * what() const throw() {
        return msg;
    }
};

#endif