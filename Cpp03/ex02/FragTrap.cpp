#include "FragTrap.hpp"

FragTrap::FragTrap()
{ 

    EnergyPoints=100;
    AttackDamage=30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string user) : ClapTrap(user)
{ 
    EnergyPoints=100;
    AttackDamage=30;
    std::cout << "FragTrap "<< Name << " create" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    Name = other.Name;
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << Name << " high five" << std::endl;
}