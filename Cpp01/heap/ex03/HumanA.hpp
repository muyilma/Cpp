#ifndef HUMANA
#define HUMANA

#include <string>
#include "Waepon.hpp"

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;
    public:
        void attack();
        HumanA(std::string Cname,Weapon &Cweapon);
};

#endif 