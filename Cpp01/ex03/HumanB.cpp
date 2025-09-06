#include "HumanB.hpp"
#include "Waepon.hpp"
#include <iostream>

void HumanB::attack()
{
    std::cout << name << "attacks with their";
    if (!weapon->getType().empty())
        std::cout << weapon->getType() << std::endl;
    else
        std::cout << " " << std::endl;
}

void HumanB::setWeapon(Weapon &Uweapon)
{
    weapon = &Uweapon;
}


HumanB::HumanB(std::string Cname)
{
    name=Cname;
}