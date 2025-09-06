#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
    std::cout << Zombie::names << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){ names=name; }

Zombie::~Zombie()
{
    std::cout << names << ":I'm die NOOOOOOO\n";
}

Zombie::Zombie()
{
    std::cout << "Zombie:I'm not a die\n";
}