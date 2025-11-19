#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{ 
    Name="Anonymous";
    HitPoints=100;
    EnergyPoints=50;
    AttackDamage=20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    Name=other.Name;
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target 
            << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
        std::cout << Name << " can't do anything" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        
        Name=other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "Gate keeper active" << std::endl;
}