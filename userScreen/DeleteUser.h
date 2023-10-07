#pragma once
#include<iostream>
#include"../classes/clsUser.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class DeleteUser:protected screen
{
public:
static void DeleteObjectUser()
{
     screen::drawScreenHeader("Delete User Screen ");
    string userName = "";
    cout << "\nPlease Enter UserName: ";
    cin>> userName;
    while (!clsUser::IsUserExist(userName))
    {
        cout << "\nUser Name is not found, choose another one: ";
        cin>>userName;
    }

    clsUser Client1 = clsUser::find(userName);
    Client1.print();

    cout << "\nAre you sure you want to delete this user y/n? ";
    
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
       

        if (Client1.Delete())
        {
            cout << "\nUser Deleted Successfully :-)\n";

            Client1.print();
        }
        else
        {
            cout << "\nError User Was not Deleted\n";
        }
    }
}

};