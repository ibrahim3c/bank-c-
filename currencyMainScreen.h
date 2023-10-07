#pragma once
#include<iostream>
#include<iomanip>
#include"screen.h"
#include"classes/inputValidate.h"
#include"currencyScreens/currencyList.h"
#include"currencyScreens/currencyFind.h"
#include"currencyScreens/currencyUpdate.h"
#include"currencyScreens/calculator.h"
using namespace std;
class CurrencyMain:protected screen{
   enum enUserMenueOptions{List=1,find=2,update=3,calculate=4,
   mainMenue=5};
   static int _ReadUserOption(){
    return input_validate::readIntNumberBetween(1,5);
   }
    static void _ShowAllCurrencyScreen(){
        showCurrencyList::ShowObjectCurrencyList();
    }
    static void _FindCurrencyScreen(){
        FindCurrency::ShowFindCurrencyScreen();
    }
    static void _UpdateCurrencyScreen(){
         UpdateCurrency::UpdateCurrencyScreen();
        }
    static void _CurrencyCalculationScreen(){
        currencyCalculator::currencyCalculatorScreen();
        }

   static void _PerfromMainMenueOption(enUserMenueOptions option){
    switch (option)
            {
            case enUserMenueOptions::List:
            {
                system("cls");
                _ShowAllCurrencyScreen();
                _GoBackToMainMenue();
                break;
            }
            case enUserMenueOptions::find:
                system("cls");
               _FindCurrencyScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::update:
                system("cls");
                _UpdateCurrencyScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::calculate:
                system("cls");
                _CurrencyCalculationScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::mainMenue:
                break;

            }
               
   }
    static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main User Menue...\n";
            system("pause>0");
            showMainCurrencyScreen();
        }
    public:
    static void showMainCurrencyScreen(){
          if (!CheckAccessRights(clsUser::enPermissions::currency))
        {
             cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
                system("pause>0");
            return;// this will exit the function and it will not continue
        }
        screen::drawScreenHeader("\n Currency Exchange Main Screen");
        
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\t Currency Exchang Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1]  List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
            cout << setw(37) << left << "" << "\t[4] Currency  Calculation .\n";
            cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << "\t\t\t Enter your choice [1:5] : ";
            _PerfromMainMenueOption((enUserMenueOptions)_ReadUserOption());

    }


};
