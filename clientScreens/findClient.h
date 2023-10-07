#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class FindClient:protected screen
{
public:
static void ShowFindClientScreen()
    {
          if (!CheckAccessRights(clsUser::enPermissions::Find))
        {
            return;// this will exit the function and it will not continue
        }

       screen::drawScreenHeader("Find Client Screen ");
        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        cin>>AccountNumber;
        while (!clsClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            cin>> AccountNumber ;
        }

        clsClient Client1 = clsClient::find(AccountNumber);

        if (!Client1.isEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        Client1.print();

    }


};