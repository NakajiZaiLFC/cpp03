#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    
}

DiamondTrap::DiamondTrap(const std::string& name)
	 : name(name), 
	   ClapTrap(name + "_clap_name"), 
	   FragTrap(), 
	   ScavTrap()
{
	this->m_hit_point = 100;
	this->m_energy_point = 50;
	this->m_attack_damage = 30;
}