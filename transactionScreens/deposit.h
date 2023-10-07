#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/inputValidate.h"
#include"../screen.h"
using namespace std;
class deposit:protected screen
{
    public:
static void depositScreen()
{
    screen::drawScreenHeader("Diposit Screen ");
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
    cout << "\nPlease enter deposit amount? ";
    Amount=input_validate::readDoubleNumber();
    cout << "\nAre you sure you want to perform this transaction? ";
    char Answer = 'n';
    cin >> Answer;
    if(Answer=='y'||Answer=='Y'){
      Client1.setAcountBalance(Client1.getAcountBalance()+Amount);
      Client1.save();
      cout << "\nAmount Deposited Successfully.\n";
      cout << "\nNew Balance Is: " << Client1.getAcountBalance();
    }
    else{
          cout<<"the operation was cancelled \n";
    }
   }
    };
 
