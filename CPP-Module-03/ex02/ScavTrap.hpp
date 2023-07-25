#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

	private:
		bool _isGuard;

	public:

		ScavTrap();
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=( const ScavTrap& copy );	
		~ScavTrap();
	
		void guardGate();

};

#endif