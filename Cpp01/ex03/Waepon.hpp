#ifndef WEAPON
#define WEAPON

#include <string>

class Weapon
{
    private:
        std::string type;
    public:
        const std::string &getType()const;
        void setType(std::string Utype);
        Weapon(std::string Utype);
        Weapon();
};

#endif 