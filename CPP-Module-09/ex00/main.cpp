/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:30:52 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/21 15:11:48 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	(void)av;
	try
	{
		if(ac != 2)
			throw MyExc("Error: Please give me input");
		Bitcoin btc;
		btc.readData();
		// btc.printMap();
		btc.readInput(av);
	}
	catch(MyExc e)
	{
		std::cerr << e.what() << '\n';
	}
}