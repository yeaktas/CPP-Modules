#include "Zombie.hpp"

int main(void) {
    Zombie z1;
    z1.setName("Zombie 1");
    z1.announce();
    std::cout << std::endl;

    Zombie *z2 = newZombie("Zombie 2");
    z2->announce();
    std::cout << std::endl;
    delete z2;
}