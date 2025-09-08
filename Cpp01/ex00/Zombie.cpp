#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << ":I'm die NOOOOOOO\n";
}

Zombie::Zombie(std::string names){ name=names; }