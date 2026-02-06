#include "ScavTrap.hpp"

int main()
{
    ScavTrap Hunter("Hunter");
    ScavTrap BigCasper("BigCasper");
    ClapTrap casper("Casper");

    std::cout << std::endl;
    std::cout << "ClapTrap " << casper.getName() << " Heal: " << casper.getHitPoints() << " EnergyPoints: " << casper.getEnergyPoints() << " AttackDamage: "<< casper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << BigCasper.getName() << " Heal: " << BigCasper.getHitPoints() << " EnergyPoints: " << BigCasper.getEnergyPoints() << " AttackDamage: "<< BigCasper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << Hunter.getName() << " Heal: " << Hunter.getHitPoints() << " EnergyPoints: " << Hunter.getEnergyPoints() << " AttackDamage: "<< Hunter.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < 4; i++)
        Hunter.attack("Casper");
    casper.takeDamage(100);
    casper.attack("Hunter");
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
        BigCasper.attack("Hunter");
    Hunter.takeDamage(80);
    Hunter.guardGate();
    BigCasper.attack("Hunter");
    std::cout << std::endl;

    std::cout << "ClapTrap " << casper.getName() << " Heal: " << casper.getHitPoints() << " EnergyPoints: " << casper.getEnergyPoints() << " AttackDamage: "<< casper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << BigCasper.getName() << " Heal: " << BigCasper.getHitPoints() << " EnergyPoints: " << BigCasper.getEnergyPoints() << " AttackDamage: "<< BigCasper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << Hunter.getName() << " Heal: " << Hunter.getHitPoints() << " EnergyPoints: " << Hunter.getEnergyPoints() << " AttackDamage: "<< Hunter.getAttackDamage() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
        Hunter.attack("BigCasper");
    BigCasper.takeDamage(100);
    BigCasper.attack("Hunter");
    Hunter.beRepaired(80);
    std::cout << std::endl;

    std::cout << "ClapTrap " << casper.getName() << " Heal: " << casper.getHitPoints() << " EnergyPoints: " << casper.getEnergyPoints() << " AttackDamage: "<< casper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << BigCasper.getName() << " Heal: " << BigCasper.getHitPoints() << " EnergyPoints: " << BigCasper.getEnergyPoints() << " AttackDamage: "<< BigCasper.getAttackDamage() << std::endl;
    std::cout << "ScavTrap " << Hunter.getName() << " Heal: " << Hunter.getHitPoints() << " EnergyPoints: " << Hunter.getEnergyPoints() << " AttackDamage: "<< Hunter.getAttackDamage() << std::endl;
    std::cout << std::endl;
}
