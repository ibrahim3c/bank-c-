#pragma once
#include<iostream>
#include<iomanip>
#include"classes/inputValidate.h"
#include"classes/clsTransfer.h"
#include"screen.h"
#include"mainScreen.h"
#include"transactionScreens/deposit.h"
#include"transactionScreens/withdraw.h"
#include"transactionScreens/totalBalance.h"
#include"transactionScreens/transferScreen.h"
using namespace std;
class transactionScreen :protected screen
{
     enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,etransfer=4,eTransferLog=5,eShowMainMenue = 6
    };
    static int _ReadTransactionMenueOption(){
    return input_validate::readIntNumberBetween(1,6);
   }
    static void _ShowDepositScreen()
    {
        deposit::depositScreen();
    } 
    static void _ShowTrasferScreen(){
        Transfer::transferScreen();
    }

    static void _ShowWithdrawScreen()
    {
       withdraw::withdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        totalBalance::ShowTotalBalances();
    }
    static void _ShowTransferLogScreen()
    {
        WhenTransfer::ShowTransferLogList();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }
     static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::etransfer:
        {
            system("cls");
            _ShowTrasferScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
            // system("pause>0");
            // mainScreen::showMainScreen();

        }
        }


    }
    public:
    static void ShowTransactionsMenue()
    {
          if (!CheckAccessRights(clsUser::enPermissions::Transaction))
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            system("pause>0");
            return;// this will exit the function and it will not continue
        }


        system("cls");
        screen::drawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
    }




};

