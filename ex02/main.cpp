#include "FragTrap.hpp"
#include <iostream>

// Helper function to print clean section headers
void print_header(const std::string& title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
    // --- 1. Testing Default Values & High Fives ---
    print_header("1. Testing Default Values & High Fives");
    
    // Test name constructor and default FragTrap values
    FragTrap f_default("Fraggy");
    
    // Test attack (should use AD: 30 as per ex02)
    std::cout << "* Fraggy attacks (should have 30 AD) *" << std::endl;
    f_default.attack("a Training Dummy"); 
    
    // Test unique ability
    std::cout << "* Fraggy requests a high five *" << std::endl;
    f_default.highFivesGuys();
    

    // --- 2. Testing Custom Constructor & Inherited Functions ---
    print_header("2. Testing Custom Constructor & Inherited Functions");
    
    // Create a custom FragTrap with low EP
    FragTrap f_custom("CustomFrag", 20, 3, 10); // HP:20, EP:3, AD:10

    std::cout << "* CustomFrag's turn... *" << std::endl;
    f_custom.attack("Target 1"); // EP: 3 -> 2
    f_custom.beRepaired(5);      // EP: 2 -> 1, HP: 20 -> 25
    f_custom.takeDamage(5);      // HP: 25 -> 20
    f_custom.attack("Target 2"); // EP: 1 -> 0

    // --- 3. Testing Exhaustion & "Dead" States ---
    print_header("3. Testing Exhaustion & \"Dead\" States");
    
    std::cout << "* CustomFrag is out of energy (EP: 0) *" << std::endl;
    f_custom.attack("Target 3"); // Fails (No EP)
    f_custom.beRepaired(1);      // Fails (No EP)

    std::cout << "\n* Testing a \"Dead\" FragTrap *" << std::endl;
    FragTrap f_dead("DeadFrag", 0, 10, 10); // HP: 0
    f_dead.attack("Target 4"); // Fails (No HP)
    f_dead.beRepaired(1);      // Fails (No HP)


    // --- 4. Testing Orthodox Canonical Form (Copy) ---
    print_header("4. Testing Orthodox Canonical Form (Copy)");
    
    std::cout << "\n* Testing Copy Constructor *" << std::endl;
    // Copy f_custom (which has EP: 0)
    FragTrap f_copy(f_custom);
    std::cout << "* Copied FragTrap tries to attack (should fail) *" << std::endl;
    f_copy.attack("Copy's Target"); // Fails (EP should be 0)

    
    std::cout << "\n* Testing Copy Assignment Operator *" << std::endl;
    FragTrap f_assign("Assigner");
    f_assign = f_custom; // Assign f_custom (EP: 0) to f_assign
    
    std::cout << "* Assigned FragTrap tries to attack (should fail) *" << std::endl;
    f_assign.attack("Assigner's Target"); // Fails (EP should be 0)

    
    // --- 5. End of main (Destructors) ---
    print_header("5. End of main (Destructors will be called)");
    
    return 0; // All destructors are called here in reverse order of creation
}
