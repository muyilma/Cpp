#include "ClapTrap.hpp"

int main()
{
    ClapTrap obj("Lucas");

    std::cout << "ClapTrap " << obj.getName() << " Heal: " << obj.getHitPoints() << " EnergyPoints: " << obj.getEnergyPoints() << " AttackDamage: "<< obj.getAttackDamage() << std::endl;
    
    for (int i = 0; i < 5; i++)
        obj.attack("enemy");
    obj.beRepaired(10);
    obj.beRepaired(10);
    std::cout << "ClapTrap " << obj.getName() << " Heal: " << obj.getHitPoints() << " EnergyPoints: " << obj.getEnergyPoints() << " AttackDamage: "<< obj.getAttackDamage() << std::endl;
    obj.takeDamage(30);
    std::cout << "ClapTrap " << obj.getName() << " Heal: " << obj.getHitPoints() << " EnergyPoints: " << obj.getEnergyPoints() << " AttackDamage: "<< obj.getAttackDamage() << std::endl;
    obj.beRepaired(100);
}
