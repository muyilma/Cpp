#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{ 
    std::cout << "ClapTrap Default constructor called" << std::endl;
    Name = "Anonymous";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    Name = other.Name;
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
}

ClapTrap::ClapTrap(const std::string user)
{
    std::cout << "ClapTrap "<< user << " create" << std::endl;
    Name = user;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target 
            << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
        std::cout << Name << " can't do anything" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints > 0)
    {
        HitPoints -= amount;
        std::cout << "ClapTrap " << Name  << " took damage " << amount  << std::endl;
    }
    else
        std::cout << Name << " can't do anything" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << Name << " take heal " << amount  << std::endl;
        HitPoints+=amount;
        EnergyPoints--;
    }
    else
        std::cout << Name << " can't do anything" << std::endl;
}

int ClapTrap::getHitPoints() const {
    return HitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return EnergyPoints;
}

int ClapTrap::getAttackDamage() const {
    return AttackDamage;
}