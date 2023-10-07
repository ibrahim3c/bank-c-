#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class AddClient:protected screen
{
    static void _readClientInfo (clsClient& Client){
    string firstName;
    string lastName;
    string email;
    string phone;
    string pincode;
    float acountbalance;
    cout << "\nEnter FirstName: ";
    cin>>firstName;
    Client.setFname(firstName) ;
    cout << "\nEnter LastName: ";
    cin>>lastName;
    Client.setLname(lastName);

    cout << "\nEnter Email: ";
    cin>>email;
    Client.setEmial(email); 

    cout << "\nEnter Phone: ";
    cin>>phone;
    Client.setPhone(phone);

    cout << "\nEnter PinCode: ";
    cin>>pincode;
    Client.setPinCode(pincode);

    cout << "\nEnter Account Balance: ";
    // acountbalance= input_validate::readFloatNumber();
    cin>>acountbalance;
    Client.setAcountBalance(acountbalance);
}

public:
static void addNewObjectClient(){
      if (!CheckAccessRights(clsUser::enPermissions::Add))
        {
            return;// this will exit the function and it will not continue
        }
     screen::drawScreenHeader("Add New Client Screen ");
     string AccountNumber = "";
    cout << "\nPlease Enter Account Number: ";
    cin>> AccountNumber;
    while (clsClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        cin>> AccountNumber;
    }

    clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);


    _readClientInfo(NewClient);

    clsClient::enSaveResult SaveResult;

    SaveResult = NewClient.save();

    switch (SaveResult)
    {
    case  clsClient::enSaveResult::succeed:
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.print();
        break;
    }
    case clsClient::enSaveResult::faild:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    }
}


};