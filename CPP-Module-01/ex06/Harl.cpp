#include "Harl.hpp"

void Harl::debug (void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\n" << std::endl;
}
void Harl::info (void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! \nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}
void Harl::warning (void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error (void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! \nI want to speak to the manager now.\n" << std::endl;
}

void Harl::complain ( std::string level ) {
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while(!levels[i].empty() && level.compare(levels[i]))
		i++;
	
	void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int a = i; a < 4; a++)
		(this->*(ptr[a]))();

	switch(i){
		case 4:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
		}
}