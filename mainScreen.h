#pragma once
#include<iostream>
#include<iomanip>
#include"screen.h"
#include"classes/inputValidate.h"
#include"classes/clsLog.h"
#include"clientScreens/showclients.h"
#include"clientScreens/AddClient.h"
#include"clientScreens/deleteClient.h"
#include"clientScreens/updateClient.h"
#include"clientScreens/findClient.h"
#include"transactionMainScreen.h"
#include"mainUser.h"
#include"currencyMainScreen.h"
#include"globalUser.h"
using namespace std;
class mainScreen:protected screen{
   enum enMainMenueOptions{showClientList=1,AddNewClient=2,DeleteCleint=3,UpdateClient=4,
   FindCLient=5,ShowTransactions=6,ManageUsers=7,logData=9,LogOut=10,currencyExchange=8,End=11};
   static int _ReadMainMenueOption(){
    return input_validate::readIntNumberBetween(1,11);
   }
    static void _ShowAllClientsScreen(){ 
        showClientsList::ShowObjectClientsList();
    }
    static void _ShowAddNewClientsScreen(){AddClient::addNewObjectClient();}
    static void _ShowDeleteClientScreen(){DeleteClient::DeleteObjectClient();}
    static void _ShowUpdateClientScreen(){UpdateClient::UpdateObjectClient();}
    static void _ShowFindClientScreen(){FindClient::ShowFindClientScreen();}
    static void _ShowTransactionsMenue(){transactionScreen::ShowTransactionsMenue();}
    static void _ShowManageUsersMenue(){mainUser::showMainUserScreen();}
    static void _ShowCurrencyExchangeMenue(){CurrencyMain::showMainCurrencyScreen();}
    static void _logout(){
        globalUser=clsUser::find("","");
    }

   static bool _PerfromMainMenueOption(enMainMenueOptions option){
    bool choice=true;
    switch (option)
            {
            case enMainMenueOptions::showClientList:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::AddNewClient:
                system("cls");
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::DeleteCleint:
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::UpdateClient:
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::FindCLient:
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::ShowTransactions:
                system("cls");
                _ShowTransactionsMenue();
                system("cls");
                mainScreen::showMainScreen();
                break;

            case enMainMenueOptions::ManageUsers:
                system("cls");
                _ShowManageUsersMenue();
                system("cls");
                mainScreen::showMainScreen();
                break;
            case enMainMenueOptions::currencyExchange:
                system("cls");
                _ShowCurrencyExchangeMenue();
                system("cls");
                mainScreen::showMainScreen();
                break;

            case enMainMenueOptions::logData:
                system("cls");
                Whenlog::ShowLogDataList();
                 _GoBackToMainMenue();
                break;
            case enMainMenueOptions::LogOut:
                system("cls");
                _logout();
                //Login();

                break;
            case enMainMenueOptions::End:
                system("cls");
                choice=false;
                break;
            }  
            return choice;
   }
    static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            system("pause>0");
            showMainScreen();
        }
    public:
    static bool showMainScreen(){
        screen::drawScreenHeader("\tMain Screen");
        
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[9] Log Register.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "\t[11] End Program.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << "\t\t\t Enter your choice [1:11] : ";
           return _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

    }

};
