#include "Waepon.hpp"
#include <iostream>

std::string Weapon::getType(){ return type; }
void Weapon::setType(std::string Utype){ type=Utype;}

Weapon::Weapon(std::string Utype)
{
    type=Utype;
}

Weapon::Weapon()
{
        std::cout << " " << std::endl;
}