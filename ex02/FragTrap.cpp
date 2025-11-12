#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Human")
{
	this->m_hit_point = 100;
	this->m_energy_point = 100;
	this->m_attack_damage = 30;
	std::cout << "🫡  FragTrap " << this->m_name << " Constructed." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->m_hit_point = 100;
	this->m_energy_point = 100;
	this->m_attack_damage = 30;
	std::cout << "🫡  FragTrap " << this->m_name << " Constructed." << std::endl;
}

FragTrap::FragTrap(const std::string& name, 
				   const int& hit_point, 
				   const int& energy_point, 
				   const int& attack_damage) 
				   : ClapTrap(name)
{
	this->m_hit_point = hit_point;
	this->m_energy_point = energy_point;
	this->m_attack_damage = attack_damage;
	std::cout << "🫡  FragTrap " << this->m_name << " Constructed." << std::endl;
}

	

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "🫡  FragTrap " << this->m_name << " Copy Constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) 
	{
		ClapTrap::operator=(other);
    }
    std::cout << "➡️  FragTrap " << this->m_name << " Copy Assignment Operator called." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "👋 FragTrap " << this->m_name << " Destructed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->m_name << " requests a high five!🤝" << std::endl;
}
