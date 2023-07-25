#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	
	ScavTrap c;
	FragTrap d;

	c.attack(d.getName());
	d.takeDamage(c.getAtack());
	d.beRepaired(10);
	d.highFivesGuys();

	return 0;
}