#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
    std::cout << Zombie::names << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    
    names=name;
}