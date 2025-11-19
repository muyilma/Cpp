#include "ScavTrap.hpp"

int main()
{
    ScavTrap a;//Test yaz

    std::cout << a.getAttackDamage() << " " << a.getEnergyPoints() << " " << a.getHitPoints() << std::endl;
    a.beRepaired(50);
    std::cout << a.getAttackDamage() << " " << a.getEnergyPoints() << " " << a.getHitPoints() << std::endl;

}
