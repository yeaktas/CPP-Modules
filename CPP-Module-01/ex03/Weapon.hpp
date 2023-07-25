#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

class Weapon{

    private:

        std::string _type;
    public:

        const std::string& getType(); 
        void setType(std::string type);

        Weapon(std::string type);
};

#endif