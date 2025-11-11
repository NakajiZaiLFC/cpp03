#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. 引数付きコンストラクタ、whoAmI、attack、継承関数のテスト ---" << std::endl;
    {
        // 引数付きコンストラクタ
        DiamondTrap dt1("Hero");
        std::cout << std::endl;

        // whoAmI: 
        // DiamondTrap::name ("Hero") と 
        // ClapTrap::m_name ("Hero_clap_name") が正しく設定されているか確認
        std::cout << "[Test: whoAmI]" << std::endl;
        dt1.whoAmI();
        std::cout << std::endl;

        // attack: ScavTrap::attack が呼び出されるか確認
        std::cout << "[Test: attack (ScavTrap::attack)]" << std::endl;
        dt1.attack("Enemy");
        std::cout << std::endl;

        // 継承された固有関数の呼び出しテスト
        // (DiamondTrap が FragTrap かつ ScavTrap であることの確認)
        std::cout << "[Test: 継承された関数]" << std::endl;
        dt1.highFivesGuys(); // FragTrapから継承
        dt1.guardGate();     // ScavTrapから継承
        std::cout << std::endl;

    } // dt1のデストラクタが呼ばれる
    std::cout << "---------------------------------------------------------" << std::endl << std::endl;


    std::cout << "--- 2. デフォルトコンストラクタのテスト ---" << std::endl;
    {
        // デフォルトコンストラクタ
        DiamondTrap dt_default;
        std::cout << std::endl;
        
        // whoAmI: 
        // DiamondTrap::name ("Human") と 
        // ClapTrap::m_name (ClapTrapのデフォルトコンストラクタで設定された名前) を確認
        std::cout << "[Test: whoAmI (Default)]" << std::endl;
        dt_default.whoAmI();
        std::cout << std::endl;
    
    } // dt_defaultのデストラクタが呼ばれる
    std::cout << "---------------------------------------" << std::endl << std::endl;


    std::cout << "--- 3. コピーコンストラクタのテスト ---" << std::endl;
    {
        DiamondTrap dt_orig("Original");
        std::cout << std::endl;

        std::cout << "[Test: コピーを作成]" << std::endl;
        // コピーコンストラクタ
        DiamondTrap dt_copy(dt_orig); 
        std::cout << std::endl;

        // コピーがオリジナルと同じ名前 (DiamondTrap::name と ClapTrap::m_name) を持つか確認
        std::cout << "[Test: whoAmI (Copy)]" << std::endl;
        dt_copy.whoAmI(); // "Original" と "Original_clap_name" のはず
        std::cout << std::endl;

        // オリジナルが変更されていないことを確認
        std::cout << "[Test: whoAmI (Original)]" << std::endl;
        dt_orig.whoAmI();
        std::cout << std::endl;
    
    } // dt_copy, dt_orig のデストラクタが呼ばれる
    std::cout << "-------------------------------------" << std::endl << std::endl;


    std::cout << "--- 4. 代入演算子のテスト ---" << std::endl;
    {
        DiamondTrap dt_assigner("Assigner");
        DiamondTrap dt_receiver("Receiver");
        std::cout << std::endl;

        std::cout << "[Test: 代入前のReceiver]" << std::endl;
        dt_receiver.whoAmI(); // "Receiver" と "Receiver_clap_name"
        std::cout << std::endl;

        std::cout << "[Test: 代入実行]" << std::endl;
        // 代入演算子
        dt_receiver = dt_assigner; 
        std::cout << std::endl;

        // ReceiverがAssignerの (ClapTrap::m_name と DiamondTrap::name) を持っているか確認
        std::cout << "[Test: 代入後のReceiver]" << std::endl;
        dt_receiver.whoAmI(); // "Assigner" と "Assigner_clap_name" のはず
        std::cout << std::endl;

    } // dt_receiver, dt_assigner のデストラクタが呼ばれる
    std::cout << "---------------------------------" << std::endl << std::endl;

    
    std::cout << "--- すべてのテストが完了しました ---" << std::endl;
    return 0;
}
