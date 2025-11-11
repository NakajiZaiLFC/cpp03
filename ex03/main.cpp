#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. Test: Parameterized Constructor, whoAmI, attack, & Inherited Functions ---" << std::endl;
    {
        // Parameterized constructor
        DiamondTrap dt1("Hero");
        std::cout << std::endl;

        // whoAmI: 
        // Check if DiamondTrap::name ("Hero") and 
        // ClapTrap::m_name ("Hero_clap_name") are set correctly
        std::cout << "[Test: whoAmI]" << std::endl;
        dt1.whoAmI();
        std::cout << std::endl;

        // attack: Check if ScavTrap::attack is called
        std::cout << "[Test: attack (ScavTrap::attack)]" << std::endl;
        dt1.attack("Enemy");
        std::cout << std::endl;

        // Test: Calling inherited unique functions
        // (Check that DiamondTrap is both a FragTrap and a ScavTrap)
        std::cout << "[Test: Inherited Functions]" << std::endl;
        dt1.highFivesGuys(); // Inherited from FragTrap
        dt1.guardGate();     // Inherited from ScavTrap
        std::cout << std::endl;

    } // dt1's destructor will be called here
    std::cout << "---------------------------------------------------------" << std::endl << std::endl;


    std::cout << "--- 2. Test: Default Constructor ---" << std::endl;
    {
        // Default constructor
        DiamondTrap dt_default;
        std::cout << std::endl;
        
        // whoAmI: 
        // Check DiamondTrap::name ("Human") and 
        // ClapTrap::m_name (name set by ClapTrap's default constructor)
        std::cout << "[Test: whoAmI (Default)]" << std::endl;
        dt_default.whoAmI();
        std::cout << std::endl;
    
    } // dt_default's destructor will be called here
    std::cout << "---------------------------------------" << std::endl << std::endl;


    std::cout << "--- 3. Test: Copy Constructor ---" << std::endl;
    {
        DiamondTrap dt_orig("Original");
        std::cout << std::endl;

        std::cout << "[Test: Creating a copy]" << std::endl;
        // Copy constructor
        DiamondTrap dt_copy(dt_orig); 
        std::cout << std::endl;

        // Check if the copy has the same names (DiamondTrap::name and ClapTrap::m_name) as the original
        std::cout << "[Test: whoAmI (Copy)]" << std::endl;
        dt_copy.whoAmI(); // Should be "Original" and "Original_clap_name"
        std::cout << std::endl;

        // Check that the original is unchanged
        std::cout << "[Test: whoAmI (Original)]" << std::endl;
        dt_orig.whoAmI();
        std::cout << std::endl;
    
    } // Destructors for dt_copy and dt_orig will be called here
    std::cout << "-------------------------------------" << std::endl << std::endl;


    std::cout << "--- 4. Test: Copy Assignment Operator ---" << std::endl;
    {
        DiamondTrap dt_assigner("Assigner");
        DiamondTrap dt_receiver("Receiver");
        std::cout << std::endl;

        std::cout << "[Test: Receiver before assignment]" << std::endl;
        dt_receiver.whoAmI(); // Should be "Receiver" and "Receiver_clap_name"
        std::cout << std::endl;

        std::cout << "[Test: Performing assignment]" << std::endl;
        // Copy assignment operator
        dt_receiver = dt_assigner; 
        std::cout << std::endl;

        // Check if Receiver now holds Assigner's names (ClapTrap::m_name and DiamondTrap::name)
        std::cout << "[Test: Receiver after assignment]" << std::endl;
        dt_receiver.whoAmI(); // Should be "Assigner" and "Assigner_clap_name"
        std::cout << std::endl;

    } // Destructors for dt_receiver and dt_assigner will be called here
    std::cout << "---------------------------------" << std::endl << std::endl;

    
    std::cout << "--- All tests completed ---" << std::endl;
    return 0;
}
