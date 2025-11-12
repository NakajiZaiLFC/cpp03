#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Human")
{
	this->m_hit_point = 100;
	this->m_energy_point = 50;
	this->m_attack_damage = 20;
	std::cout << "🫡  ScavTrap " << this->m_name << " Constructed." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->m_hit_point = 100;
	this->m_energy_point = 50;
	this->m_attack_damage = 20;
	std::cout << "🫡  ScavTrap " << this->m_name << " Constructed." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name, 
				   const int& hit_point, 
				   const int& energy_point, 
				   const int& attack_damage) 
				   : ClapTrap(name)
{
	this->m_hit_point = hit_point;
	this->m_energy_point = energy_point;
	this->m_attack_damage = attack_damage;
	std::cout << "🫡  ScavTrap " << this->m_name << " Constructed." << std::endl;
}

	

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "🫡  ScavTrap " << this->m_name << " Copy Constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) 
	{
		ClapTrap::operator=(other);
    }
    std::cout << "➡️  ScavTrap " << this->m_name << " Copy Assignment Operator called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "👋 ScavTrap " << this->m_name << " Destructed." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "✅ ScavTrap " << this->m_name << " is now in Gate keeper mode!🛡" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->m_energy_point < 1)
	{
		std::cout << "❌ ScavTrap " << this->m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << "😵 \"Need more energy point...☕\"" << std::endl;
	}
	else if (this->m_hit_point < 1)
	{
		std::cout << "❌ ScavTrap " << this->m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << "😵 \"Need more HP...🛌\"" << std::endl;
	}	
	else
	{
		std::cout << "✅ ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attack_damage << " points of damage !😎" << std::endl;
		this->m_energy_point--;
	}
}
