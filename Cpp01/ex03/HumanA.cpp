#include "HumanA.hpp"
#include <iostream>

void HumanA::attack()
{
    std::cout << name << "attacks with their" << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string Cname,Weapon &Cweapon) : name(Cname) , weapon(Cweapon){}