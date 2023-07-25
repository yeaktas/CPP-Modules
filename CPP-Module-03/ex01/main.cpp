#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){

	ClapTrap a;
	ClapTrap b;
	
	a.attack(b.getName());
	b.takeDamage(a.getAtack());
	b.beRepaired(1);
	
	ScavTrap c;
	ScavTrap d;

	c.attack(d.getName());
	d.takeDamage(c.getAtack());
	d.beRepaired(10);
	d.guardGate();
	return 0;
}