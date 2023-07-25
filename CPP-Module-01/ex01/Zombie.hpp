#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string Name;
	public:

	Zombie();
	Zombie(std::string);	
	~Zombie();
	
	void announce( void );
	
	void setName(std::string);
	std::string getName( void );
};

Zombie* zombieHorde( int N, std::string name );


#endif