#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    // --- 1. TEST of Orthodox Canonical Form (OCF) ---
    std::cout << "--- 1. Testing Orthodox Canonical Form ---" << std::endl;
    ClapTrap default_trap;

    ClapTrap named_trap("Bob");
    ClapTrap custom_trap("Eve", 15, 5, 2);
    ClapTrap copy_trap(custom_trap);
    std::cout << "\n--- Testing Copy Assignment (default_trap = custom_trap) ---" << std::endl;
    default_trap = custom_trap;
    std::cout << std::endl;


    // --- 2. TEST of attack() ---
    std::cout << "--- 2. Testing attack() ---" << std::endl;
    ClapTrap attacker("Attacker", 10, 2, 5); // HP:10, EP:2, AD:5

    // (EP:2 -> 1)
    attacker.attack("Target-1");
    // (EP:1 -> 0)
    attacker.attack("Target-2");
    // (EP:0)
    attacker.attack("Target-3");

    ClapTrap dead_attacker("DeadAttacker", 0, 10, 5); // HP:0, EP:10, AD:5
    dead_attacker.attack("Target-4");
    std::cout << std::endl;


    // --- 3. TEST of beRepaired() ---
    std::cout << "--- 3. Testing beRepaired() ---" << std::endl;
    ClapTrap repairer("Repairer", 10, 2, 0); // HP:10, EP:2

    // (EP:2 -> 1, HP:10 -> 15)
    repairer.beRepaired(5);
    // (EP:1)
    repairer.beRepaired(0);
    // (EP:1 -> 0, HP:15 -> 20)
    repairer.beRepaired(5);
    // (EP:0)
    repairer.beRepaired(5);

    ClapTrap dead_repairer("DeadRepairer", 0, 10, 0); // HP:0, EP:10
    dead_repairer.beRepaired(10);
    std::cout << std::endl;


    // --- 4. TEST of takeDamage() ---
    std::cout << "--- 4. Testing takeDamage() ---" << std::endl;
    ClapTrap victim("Victim", 10, 10, 0); // HP:10

    // (HP:10 -> 5)
    victim.takeDamage(5);
    // amount == 0 (HP:5)
    victim.takeDamage(0);
    // (HP:5 -> 0)
    victim.takeDamage(100);
    // (HP:0)
    victim.takeDamage(5);
    std::cout << std::endl;


    std::cout << "--- 5. End of main (Destructors will be called) ---" << std::endl;
    
    return 0;
}
