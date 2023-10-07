#pragma once
#include<iostream>
#include"classes/clsUser.h"
#include"classes/clsLog.h"
#include"screen.h"
#include"globalUser.h"
#include"mainScreen.h"
using namespace std;
class Login:public screen
{
    static bool block(){
        cout<<"sorry you are locked after 3 trials \n";
        return false;
    }
    static bool _login(){
        int trials=3;
        string userName,password;
       cout << "Enter Username? ";
            cin >> userName;

        cout << "Enter Password? ";
            cin >> password;
       while (!clsUser::IsUserExistToLog(userName,password))
      {
        trials--;
        if (trials==0)  return block();
        cout << "\nUserName or Password is not wrong \n "
            <<"you have " <<trials<<" Trial(s) to login \n";
        cout << "Enter Username? ";
            cin >> userName;

        cout << "Enter Password? ";
            cin >> password;
      }
        globalUser = clsUser::find(userName, password);
        Whenlog::addDataWhenLog();
        return mainScreen::showMainScreen();

    }
    public:
    static bool LoginScreen(){
        system("cls");
        screen::drawScreenHeader("\t  Login Screen");
        return _login();
    }

};
