#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/inputValidate.h"
#include"../screen.h"
using namespace std;
class withdraw:protected screen
{
    public:
static void withdrawScreen()
{
    screen::drawScreenHeader("withdraw Screen ");
    string AccountNumber = "";
    cout << "\nPlease Enter client Account Number: ";
    cin>>AccountNumber;
    clsClient Client1 = clsClient::find(AccountNumber);
    while(!clsClient::IsClientExist(AccountNumber)){
        cout<<"this acount number does not exist !!"
        << "\nPlease Enter another client Account Number: ";
        cin>>AccountNumber;
 
    }

    Client1.print();
    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    Amount=input_validate::readDoubleNumber();
    while(Amount>Client1.getAcountBalance()){
        cout<<"the amount is bigger than you balance!! pls enter another amount.";
        Amount=input_validate::readDoubleNumber();
    }
    cout << "\nAre you sure you want to perform this transaction? ";
    char Answer = 'n';
    cin >> Answer;
    if(Answer=='y'||Answer=='Y'){
      cout<<"the amount is"<<Amount;
       double newBalance=Client1.getAcountBalance()-Amount;
      Client1.setAcountBalance(newBalance);
      Client1.save();
      cout << "\nAmount withdrew Successfully.\n";
      cout << "\nNew Balance Is: " << Client1.getAcountBalance();
    }
    else{
          cout<<"the operation was cancelled \n";
    }
   }
    };
 
