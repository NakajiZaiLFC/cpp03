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

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	const std::string getName(void) const;

private:
	std::string m_name;
	int m_hit_point;
	int m_energy_point;
	int m_attack_damage;
};

#endif
