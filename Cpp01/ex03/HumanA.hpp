#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Waepon.hpp"

class HumanA
{
    private:
     std::string name;
     Weapon &weapon;
    public:
        void attack();
        HumanA(std::string Cname,Weapon &Cweapon);
};

#endif 