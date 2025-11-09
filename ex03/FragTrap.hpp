#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{
public:
    FragTrap();
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

	FragTrap(const std::string& name);
	FragTrap(const std::string& name, const int& hit_point, const int& energy_point, const int& attack_damage);

	void highFivesGuys(void);
private:
    
};

#endif
