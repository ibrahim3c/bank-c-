#pragma once
#include<iostream>
#include<iomanip>
#include"screen.h"
#include"classes/inputValidate.h"
#include"userScreen/usersList.h"
#include"userScreen/AddUser.h"
#include"userScreen/DeleteUser.h"
#include"userScreen/FindUser.h"
#include"userScreen/UpdateUser.h"
#include"classes/clsUser.h"
using namespace std;
class mainUser:protected screen{
   enum enUserMenueOptions{usersList=1,AddNewUser=2,DeleteUser=3,UpdateUser=4,
   FindUser=5,mainMenue=6};
   static int _ReadUserOption(){
    return input_validate::readIntNumberBetween(1,6);
   }
    static void _ShowAllUsersScreen(){
        showUsersList::ShowObjectUsersList();
    }
    static void _ShowAddNewUserScreen(){
        AddUser::addNewObjectUser();
    }
    static void _ShowDeleteUserScreen(){
        DeleteUser::DeleteObjectUser();

        }
    static void _ShowUpdateUserScreen(){
        UpdateUser::UpdateObjectUser();
        }
    static void _ShowFindUserScreen(){
        FindUser::ShowFindUserScreen();
        }

   static void _PerfromMainMenueOption(enUserMenueOptions option){
    switch (option)
            {
            case enUserMenueOptions::usersList:
            {
                system("cls");
                _ShowAllUsersScreen();
                _GoBackToMainMenue();
                break;
            }
            case enUserMenueOptions::AddNewUser:
                system("cls");
               _ShowAddNewUserScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::DeleteUser:
                system("cls");
                _ShowDeleteUserScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::UpdateUser:
                system("cls");
                _ShowUpdateUserScreen();
                _GoBackToMainMenue();
                break;

            case enUserMenueOptions::FindUser:
                system("cls");
                _ShowFindUserScreen();
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
            showMainUserScreen();
        }
    public:
    static void showMainUserScreen(){
          if (!CheckAccessRights(clsUser::enPermissions::ManageUsers))
        {
             cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
                system("pause>0");
            return;// this will exit the function and it will not continue
        }
        screen::drawScreenHeader("\n User Screen");
        
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain User Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << "\t\t\t Enter your choice [1:6] : ";
            _PerfromMainMenueOption((enUserMenueOptions)_ReadUserOption());

    }


};
