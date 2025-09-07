#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
    std::cout << Zombie::names << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << names << ":I'm die NOOOOOOO\n";
}

Zombie::Zombie(std::string name){ names=name; }