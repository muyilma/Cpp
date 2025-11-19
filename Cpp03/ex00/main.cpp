#include "ClapTrap.hpp"

int main()
{
    ClapTrap obj;
    ClapTrap copyObj("mustafa");
    
    obj.attack("enemy");
    obj.beRepaired(10);
    obj.takeDamage(10);
    
    for (int i = 0; i < 10; i++)
        obj.attack("enemy");
}
