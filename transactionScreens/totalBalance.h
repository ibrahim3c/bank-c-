#pragma once
#include<iostream>
#include"../classes/clsClient.h"
#include"../classes/inputValidate.h"
#include"../screen.h"
using namespace std;
class totalBalance:screen
{
static void _PrintClientRecordBalanceLine(clsClient Client)
{

    cout << "| " << setw(15) << left << Client.getAcountNumber();
    cout << "| " << setw(40) << left << Client.getFname()+" "+Client.getLname();
    cout << "| " << setw(12) << left << Client.getAcountBalance();

}
public:
static void ShowTotalBalances()
{
    vector <clsClient> vClients = clsClient::getClients();
    string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";
    screen::drawScreenHeader("\t Show Total Balance Screen",SubTitle);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsClient Client : vClients)
        {
            _PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " <<NumberToText(TotalBalances) << ")";
}



};