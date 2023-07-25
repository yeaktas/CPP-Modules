#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
		std::string _name;
		int _hitPoint;
		int _energyPoint;
		int _atackDamage;

	public:

		ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=( const ClapTrap& copy );	
		~ClapTrap();

		int getAtack(void);
		std::string getName(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

 #endif
