#ifndef HUMANBHPP_
#define HUMANBHPP_

#include "Weapon.hpp"

class HumanB {

    private:

        std::string _name;
        Weapon* _Weapon;
    public:

        void attack( void );
    
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &Weapon);

};

#endif