/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:35 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 18:40:36 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &r) {
    *this = r;
}

RPN& RPN::operator=(const RPN &r) {
    this->_stack = r._stack;
    return *this;
}

double RPN::evaluate(const std::string& expr) {
    std::istringstream iss(expr);
    std::string token;
    while(iss >> token) {
        if(token.length() > 1) {
            throw MyExc("Error: Only between 0-9");
        }
        if(isdigit(token[0])) {
            std::stringstream ss(token);
            double value;
            ss >> value;
            _stack.push(value);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                throw MyExc("Error: not enough operands");
            }
            double rhs = _stack.top();
            _stack.pop();
            double lhs = _stack.top();
            _stack.pop();
            if(token == "+") {
                _stack.push(lhs + rhs);
            } else if (token == "-") {
                _stack.push(lhs - rhs);
            } else if (token == "*") {
                _stack.push(lhs * rhs);
            } else if (token == "/") {
                if (rhs == 0) {
                    throw MyExc("Error: division by zero");
                }
                _stack.push(lhs / rhs);
            }
        } else {
            throw MyExc("Error: invalid token");
        }
    }
    if (_stack.size() != 1) {
        throw MyExc("Error: too many operands");
    }
    double res = _stack.top();
    _stack.pop();
    return res;
}