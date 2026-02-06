#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap pirate("Pirate");
    ScavTrap hunter("Hunter");
    ClapTrap protector("Protector");

    std::cout << std::endl;
    std::cout << "ClapTrap " << protector.getName() << " Heal: " << protector.getHitPoints() << " EnergyPoints: " << protector.getEnergyPoints() << " AttackDamage: "<< protector.getAttackDamage() << std::endl;
    std::cout << "ScacTrap " << hunter.getName() << " Heal: " << hunter.getHitPoints() << " EnergyPoints: " << hunter.getEnergyPoints() << " AttackDamage: "<< hunter.getAttackDamage() << std::endl;
    std::cout << "FragTrap " << pirate.getName() << " Heal: " << pirate.getHitPoints() << " EnergyPoints: " << pirate.getEnergyPoints() << " AttackDamage: "<< pirate.getAttackDamage() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
        pirate.attack("Protector");
    protector.takeDamage(100);
    protector.attack("Pirate");
    std::cout << std::endl;

    pirate.highFivesGuys();
    for (int i = 0; i < 5; i++)
        hunter.attack("Pirate");
    pirate.takeDamage(100);
    pirate.attack("Hunter");
    std::cout << std::endl;
}
