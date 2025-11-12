#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
public:
    ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

	ScavTrap(const std::string& name);
	ScavTrap(const std::string& name, const int& hit_point, const int& energy_point, const int& attack_damage);
	void guardGate();
	void attack(const std::string& target);
};

#endif
