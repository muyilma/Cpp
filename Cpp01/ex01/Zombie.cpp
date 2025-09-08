#include "Zombie.hpp"
#include <iostream>

void Zombie::announce()
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string setName){ name=setName;}

Zombie::Zombie()
{

}
