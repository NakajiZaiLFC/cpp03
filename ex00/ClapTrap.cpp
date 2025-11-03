#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : m_name("Human"), m_hit_point(10), m_energy_point(10), m_attack_damage(0)
{
	std::cout << "🫡 ClapTrap " << m_name << " Constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_hit_point(10), m_energy_point(10), m_attack_damage(0)
{
	std::cout << "🫡  ClapTrap " << m_name << " Constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "👋 ClapTrap " << m_name << " Destructed." << std::endl;
}

const std::string ClapTrap::getName(void) const
{
	return m_name;
}

/**
 * Attacking and repairing each cost 1 energy point.
 */
void ClapTrap::attack(const std::string &target)
{
	if (m_energy_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << "😵‍💫 \"Need more energy point...☕\"" << std::endl;
	}
	else if (m_hit_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot attack to " << target << "." << std::endl;
		std::cout << m_name << "😵‍💫 \"Need more HP...🛌\"" << std::endl;
	}	
	else
	{
		std::cout << "✅ ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << "points of damage !😎" << std::endl;
		m_energy_point--;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energy_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot repairs itself." << std::endl;
		std::cout << m_name << "😵‍💫\"Need more energy point...☕\"" << std::endl;
	}
	else if (m_hit_point < 1)
	{
		std::cout << "❌ ClapTrap " << m_name << " cannot repairs itself." << std::endl;
		std::cout << m_name << "😵‍💫\"Need more HP...🛌\"" << std::endl;
	}
	else if (amount == 0)
	{
		std::cout << "❓ ClapTrap " << m_name << "😑\"What do you want to do?\"" << std::endl;
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
		std::cout << "❓ClapTrap " << m_name << "😑\"What do you want to do?\"" << std::endl;
	}
	else
	{
		std::cout << "✅ ClapTrap " << m_name << " takes " << amount << " points of damage!😎" << std::endl;
		if (amount > static_cast<unsigned int>(m_hit_point))
			m_hit_point = 0;
		else
			m_hit_point -= amount;
	}
}
