// AI/SYSTEM/LOGIC/ACCOUNT/BANKING.H    --  USED BY "AI/SYSTEM/LOGIC/ACCOUNT/ACCOUNT.H"

#include <iostream>

void draw_banking_menu() {
    std::cout << std::endl << std::endl;
    std::cout << "(banking engine) function() : " << std::endl;
    std::cout << "\t( 1) // ai.add_account(1);" << std::endl;
    std::cout << "\t( 2) // ai.subtract_account(10);" << std::endl;
    std::cout << "\t( 3) // ai.change_account(10);" << std::endl;
    std::cout << "\t( 4) // ai.printn_account();" << std::endl;
    std::cout << "\t( 5) // ai.total_account();" << std::endl;
    std::cout << "\t( 6) // ai.list_positive();" << std::endl;
    std::cout << "\t( 7) // ai.list_negative();" << std::endl;
    std::cout << "\t( 8) // ai.average_account();" << std::endl;
    std::cout << "\t( 9) // ai.transfer(1,200,20.00);" << std::endl;
    std::cout << "\t(10) // ai.store_accounts_detail();" << std::endl;
    std::cout << "\t(11) // ai.export_accounts(exp_account);" << std::endl;
    std::cout << "\t(12) // ai.import_accounts(imp_account);" << std::endl;
    std::cout << std::endl;
    std::cout << "\t(99) QUIT();" << std::endl;
    std::cout << std::endl << ":: ";
};

// eof