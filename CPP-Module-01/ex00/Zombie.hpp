#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string Name;
	public:

	~Zombie();
	
	void announce( void );
	
	void setName(std::string);
	std::string getName( void );
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );


#endif