#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: m_name("Human"),
	  m_hit_point(10), 
	  m_energy_point(10), 
	  m_attack_damage(0)
{
	std::cout << "🫡  ClapTrap " << m_name << " Constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: m_name(name), 
	  m_hit_point(10), 
	  m_energy_point(10),
	  m_attack_damage(0)
{
	std::cout << "🫡  ClapTrap " << m_name << " Constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, 
				   const int& hit_point, 
				   const int& energy_point, 
				   const int& attack_damage)
	: m_name(name),
	  m_hit_point(hit_point),
	  m_energy_point(energy_point), 
	  m_attack_damage(attack_damage)
{
	std::cout << "🫡  ClapTrap " << m_name << " Constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name(other.m_name), 
	  m_hit_point(other.m_hit_point), 
	  m_energy_point(other.m_energy_point), 
	  m_attack_damage(other.m_attack_damage)
{
	std::cout << "🖨  ClapTrap " << this->m_name << " Copy Constructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hit_point = other.m_hit_point;
		this->m_energy_point = other.m_energy_point;
		this->m_attack_damage = other.m_attack_damage;
	}
	std::cout << "➡️  ClapTrap " << this->m_name << " Copy Assignment Operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "👋 ClapTrap " << m_name << " Destructed." << std::endl;
}


/**
 * Attacking and repairing each cost 1 energy point.
 */
void ClapTrap::attack(const std::string &target)
{
	if (m_energy_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << " 😵 \"Need more energy point...☕\"" << std::endl;
	}
	else if (m_hit_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << " 😵 \"Need more HP...🛌\"" << std::endl;
	}	
	else
	{
		std::cout << "✅ ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage !😎" << std::endl;
		m_energy_point--;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energy_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot repairs itself." << std::endl;
		std::cout << m_name << " 😵 \"Need more energy point...☕\"" << std::endl;
	}
	else if (m_hit_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot repairs itself." << std::endl;
		std::cout << m_name << " 😵 \"Need more HP...🛌\"" << std::endl;
	}
	else if (amount == 0)
	{
		std::cout << "❓ ClapTrap " << m_name << " 😑 \"What do you want to do?\"" << std::endl;
	}
	else
	{
		std::cout << "✅ ClapTrap " << m_name << " repairs itself, gaining " << amount << " hit points!🍺😎" << std::endl;
		m_hit_point += amount;
		m_energy_point--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hit_point < 1 || amount == 0)
	{
		std::cout << "❓ ClapTrap " << m_name << " 😑 \"What do you want to do?\"" << std::endl;
	}
	else
	{
		std::cout << "✅ ClapTrap " << m_name << " takes " << amount << " points of damage!😭" << std::endl;
		if (amount > m_hit_point)
			m_hit_point = 0;
		else
			m_hit_point -= amount;
	}
}
