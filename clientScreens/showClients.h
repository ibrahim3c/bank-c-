#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class showClientsList:protected screen
{
static void _printClientRecordLine(clsClient c){
    cout << "| " << left << setw(15) <<c.getAcountNumber() ;
    cout << "| " << left << setw(20) << c.getFname()+" "+c.getLname();
    cout << "| " << left << setw(12) << c.getPhone();
    cout << "| " << left << setw(20) << c.getEmial();
    cout << "| " << left << setw(15) << c.getPinCode();
    cout << "| " << left << setw(12) << c.getAcountBalance();
}
public:
static void ShowObjectClientsList()
{   
      if (!CheckAccessRights(clsUser::enPermissions::List))
        {
            return;// this will exit the function and it will not continue
        } 

    vector <clsClient> vClients = clsClient::getClients();
    string Title = "\t  Client List Screen";
    string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";
    screen::drawScreenHeader(Title,SubTitle);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsClient Client : vClients)
        {

            _printClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

};