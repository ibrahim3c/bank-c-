#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class UpdateClient:protected screen
{
    static  void readClientInfo (clsClient& Client){
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
static void UpdateObjectClient()
{
      if (!CheckAccessRights(clsUser::enPermissions::Update))
        {
            return;// this will exit the function and it will not continue
        }
    screen::drawScreenHeader("Update Client Screen ");
    string AccountNumber = "";
    cout << "\nPlease Enter client Account Number: ";
    cin>>AccountNumber;
    clsClient Client1 = clsClient::find(AccountNumber);
    while (Client1.isEmpty())
    {
        cout << "\nAccount number is not found, choose another one: ";
        cin>>AccountNumber ;
    }

    Client1.print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";

  
    readClientInfo(Client1);

    clsClient::enSaveResult SaveResult;
    SaveResult = Client1.save();
    switch (SaveResult)
    {
    case  clsClient::enSaveResult::succeed:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.print();
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