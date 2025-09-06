#ifndef WEAPON
#define WEAPON

#include <string>

class Weapon
{
    private:
        std::string type;
    public:
        std::string getType();
        void setType(std::string Utype);
        Weapon(std::string Utype);
        Weapon();
};

#endif 