#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class DeleteClient:protected screen
{
public:
static void DeleteObjectClient()
{ 
      if (!CheckAccessRights(clsUser::enPermissions::del))
        {
            return;// this will exit the function and it will not continue
        }
     screen::drawScreenHeader("Delete Client Screen ");
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number: ";
    cin>> AccountNumber;
    while (!clsClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        cin>>AccountNumber;
    }

    clsClient Client1 = clsClient::find(AccountNumber);
    Client1.print();

    cout << "\nAre you sure you want to delete this client y/n? ";
    
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
       

        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            Client1.print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}

};