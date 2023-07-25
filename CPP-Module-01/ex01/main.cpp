#include "Zombie.hpp"

int main(void) {
    
    Zombie* z;
    std::string a =  "Zombies";
    int n = 5;
    z = zombieHorde(n, a);

    for(int i = 0; i < n; i++){
        z[i].announce();
    }
    delete[] z;

}