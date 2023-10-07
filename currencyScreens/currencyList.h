#pragma once
#include<iostream>
#include"../classes/clsCurrency.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class showCurrencyList:protected screen
{
static void _printCurrencyRecordLine(clsCurrency c){
   cout << "| " << left << setw(30) <<c.getCountry() ;
    cout << "| " << left << setw(5) << c.getCurrencyCode();
    cout << "| " << left << setw(40) << c.getCurrencyName();
    cout << "| " << left << setw(5) << c.getRate();
}
public:
static void ShowObjectCurrencyList()
{    

    vector <clsCurrency> vClients = clsCurrency::getCurrencies();
    string Title = "\t  Currencies List Screen";
    string SubTitle ="\t    (" + to_string(vClients.size()) + ") Currency.";
    screen::drawScreenHeader(Title,SubTitle);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(30) << "Country";
    cout << "| " << left << setw(5) << "code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(5) << "Rate(1$)";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Currencies Available In the System!";
    else

        for (clsCurrency &c : vClients)
        {

            _printCurrencyRecordLine(c);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

};
