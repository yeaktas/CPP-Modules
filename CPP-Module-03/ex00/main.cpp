#include "ClapTrap.hpp"

int main(){

	ClapTrap a;
	ClapTrap b;

	a.attack(b.getName());
	b.takeDamage(a.getAtack());
	b.beRepaired(1);

	return 0;
}