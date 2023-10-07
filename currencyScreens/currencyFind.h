#pragma once
#include<iostream>
#include<string>
#include"../classes/clsCurrency.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class FindCurrency:protected screen
{
    static void findByCode(string code){
        clsCurrency c = clsCurrency::findByCode(code);

        if (!c.isEmpty())
        {
            cout << "\n Found :-)\n";
        }
        else
        {
            cout << "\n not Found :-(\n";
        }

        c.printCard();
    }
    static void findByCountry(string country){
        clsCurrency c = clsCurrency::findByCountry(country);

        if (!c.isEmpty())
        {
            cout << "\n Found :-)\n";
        }
        else
        {
            cout << "\n not Found :-(\n";
        }

        c.printCard();
    }
public:
static void ShowFindCurrencyScreen()
    {

       screen::drawScreenHeader("Find Currency Screen ");
        string code;
        string country;
        char anyFind;
        cout<<"find by : [1] code or [2] country ?";
        anyFind=input_validate::readIntNumberBetween(1,2);
        if(anyFind==1){
            cout << "\nPlease Enter CurrencyCode : ";cin>>code;
             while (!clsCurrency::IsCurrencyExistByCode(code))
            {
                cout << "\ncode is not found, choose another one: ";
                 cin>>code;
             }
             findByCode(code);
        }
        else{
            cout << "\nPlease Enter CurrencyCountry : ";cin>>country;
             while (!clsCurrency::IsCurrencyExistByCounter(country))
            {
                cout << "\ncode is not found, choose another one: ";
                 cin>>code;
             }
             findByCountry(country);
        }
      

    }


};