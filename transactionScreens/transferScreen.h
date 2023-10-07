#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/inputValidate.h"
#include"../classes/clsTransfer.h"
#include"../screen.h"
using namespace std;
class Transfer:protected screen
{
    public:
static void transferScreen()
{
    screen::drawScreenHeader("Transfer Screen ");
    string AccountNumber = "";
    string AccountNumber2 = "";
    cout << "\nPlease Enter  Account Number to Transfer from : ";
    cin>>AccountNumber;
    clsClient Client1 = clsClient::find(AccountNumber);
    while(!clsClient::IsClientExist(AccountNumber)){
        cout<<"this acount number does not exist !!"
        << "\nPlease Enter another client Account Number: ";
        cin>>AccountNumber;
    }

    Client1.printClientCard();
    cout<<"Please Enter  Account Number to Transfer to ";
    cin>>AccountNumber2;
     clsClient Client2 = clsClient::find(AccountNumber2);
    while((!clsClient::IsClientExist(AccountNumber2))|| (AccountNumber2==AccountNumber)){
        cout<<"this acount number does not exist !!"
        << "\nPlease Enter another client Account Number: ";
        cin>>AccountNumber2;
    }
    Client2.printClientCard();
    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    Amount=input_validate::readDoubleNumber();
     while(Amount>Client1.getAcountBalance()){
        cout<<"the amount Exceeda the Available!! pls enter another amount.";
        Amount=input_validate::readDoubleNumber();
    }
    cout << "\nAre you sure you want to perform this transaction? ";
    char Answer = 'n';
    cin >> Answer;
    if(Answer=='y'||Answer=='Y'){
       double balance1=0;
       double balance2=0;
       balance1=Client1.getAcountBalance()-Amount;
       balance2=Client2.getAcountBalance()+Amount;
      Client1.setAcountBalance(balance1);
      Client1.save();
      Client2.setAcountBalance(balance2);
      Client2.save();
      cout << "\n Transfer done Successfully.\n";
      Client1.printClientCard();
      Client2.printClientCard();
      WhenTransfer::addDataWhenTransfer(Amount,Client1,Client2);
    }
    else{
          cout<<"the operation was cancelled \n";
    }
   }
    };
 
