#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Waepon.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        void attack();
        HumanB(std::string Cname);
        void setWeapon(Weapon &Uweapon);
};

#endif 