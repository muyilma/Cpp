#include "HumanB.hpp"
#include "Waepon.hpp"
#include <iostream>

void HumanB::attack()
{
    if (weapon){
        std::cout << name << " attacks with their " ;
        std::cout << weapon->getType() << std::endl;
    }
    else
        std::cout << name << " has no weapon so "<< name <<  " running away" << std::endl;
}

void HumanB::setWeapon(Weapon &Uweapon)
{
    weapon = &Uweapon;
}


HumanB::HumanB(std::string Cname)
{
    weapon=NULL;
    name=Cname;
}