#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	ClapTrap(const std::string &name);
	ClapTrap(const std::string& name, const int& hit_point, const int& energy_point, const int& attack_damage);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string m_name;
	unsigned int m_hit_point;
	unsigned int m_energy_point;
	unsigned int m_attack_damage;
};

#endif
