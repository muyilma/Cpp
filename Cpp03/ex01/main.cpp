#include "ScavTrap.hpp"

int main()
{
    ScavTrap a;

    std::cout << a.getAttackDamage() << " " << a.getEnergyPoints() << " " << a.getHitPoints() << std::endl;
    a.beRepaired(50);
    std::cout << a.getAttackDamage() << " " << a.getEnergyPoints() << " " << a.getHitPoints() << std::endl;

}
