#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;
    public:
        const std::string &getType()const;
        void setType(std::string Utype);
        Weapon(std::string Utype);
};

#endif 