#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

    private:

        std::string _name;
        Weapon& _Weapon;
        
    public:

        void attack( void );
    
        HumanA(std::string name, Weapon& Weapons);
        ~HumanA();

};

#endif