#pragma once
#include<iostream>
#include"../classes/clsUser.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class FindUser:protected screen
{
public:
static void ShowFindUserScreen()
    {

       screen::drawScreenHeader("Find User Screen ");
        string userName;
       cout << "\nPlease Enter UserName: ";
        cin>> userName;
       while (!clsUser::IsUserExist(userName))
      {
        cout << "\nUser Name is not found, choose another one: ";
        cin>>userName;
      }

        clsUser Client1 = clsUser::find(userName);

        if (!Client1.isEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        Client1.print();

    }


};