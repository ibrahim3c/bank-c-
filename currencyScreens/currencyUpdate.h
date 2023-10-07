#pragma once
#include<iostream>
#include"../classes/clsCurrency.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class UpdateCurrency:protected screen
{
 
public:
static void UpdateCurrencyScreen()
{
     
    screen::drawScreenHeader("Update Currency Screen ");
    string code = "";
    cout << "\nPlease Enter Currency code: ";
    cin>>code;
    clsCurrency c = clsCurrency::findByCode(code);
    while (c.isEmpty())
    {
        cout << "\n not found, choose another one: ";
        cin>>code ;
        c = clsCurrency::findByCode(code);
    }

    c.printCard();
    float rate;
    cout<<"enter new Currency Rate : "; cin>>rate;

    char choice;
    cout<<"are u sure [y/n] ?";cin>>choice;

    if(choice=='y'||choice=='Y')
    {
        c.UpdateRate(rate);
        cout << "\n Currency rate Updated Successfully :-)\n";
        c.printCard();
     
    }
    else{
        cout<<"the operation was canceled \n";
    }
  
    
}

};