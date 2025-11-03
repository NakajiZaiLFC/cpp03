#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Jack");
	a.attack("targetA");
	a.takeDamage(5);
	a.beRepaired(3);
	a.attack("targetB");
	return 0;
}
