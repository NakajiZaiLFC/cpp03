#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : m_name("Human")
{
	this->m_hit_point = 100;
	this->m_energy_point = 50;
	this->m_attack_damage = 30;
	std::cout << "💎  DiamondTrap " << m_name << " Constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	  FragTrap(other),
	  ScavTrap(other),
	  m_name(other.m_name)
{
	std::cout << "💎  DiamondTrap " << m_name << " Copy Constructed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->m_name = other.m_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "👋 DiamondTrap " << m_name << " Destructed." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(),
	  ScavTrap(),
	  m_name(name)
{
	this->m_hit_point = 100;
	this->m_energy_point = 50;
	this->m_attack_damage = 30;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->m_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::m_name << std::endl;
}
