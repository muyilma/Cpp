#include "Waepon.hpp"
#include <iostream>

const std::string &Weapon::getType()const{ return type; }
void Weapon::setType(std::string Utype){ type=Utype;}

Weapon::Weapon(std::string Utype)
{
    type=Utype;
}

Weapon::Weapon()
{
    std::cout << " " << std::endl;
}