#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{ 
    HitPoints=100;
    EnergyPoints=50;
    AttackDamage=20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
}

ScavTrap::~ScavTrap()
{
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
}
