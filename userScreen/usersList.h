// #pragma once
// #include<iostream>
// #include"../classes/clsUser.h"
// #include"../classes/client.h"
// #include"../classes/inputValidate.h"
// #include<iomanip>
// #include"../screen.h"
// using namespace std;
// enum enMode{emptyMode=0,updateMode=1,addNew=2};
// class usersList:protected screen
// {
//     static void _printUserRecordLine(clsUser c){
//     cout << "| " << left << setw(15) <<c.getUserName() ;
//     cout << "| " << left << setw(20) << c.getFname()+" "+c.getLname();
//     cout << "| " << left << setw(12) << c.getPhone();
//     cout << "| " << left << setw(20) << c.getEmial();
//     cout << "| " << left << setw(15) << c.getPassword();
//     cout << "| " << left << setw(12) << c.getPermission();
// }
// public :
// static void ShowUsersList(){
//    vector <clsUser> vClients=clsUser::loadUsersFromFile() ;
//     string Title = "\t  Users List Screen";
//     string SubTitle ="\t    (" + to_string(vClients.size()) + ") users(s).";
//     screen::drawScreenHeader(Title,SubTitle);
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n" << endl;

//     cout << "| " << left << setw(15) << "User Name";
//     cout << "| " << left << setw(20) << "Full Name";
//     cout << "| " << left << setw(12) << "Phone";
//     cout << "| " << left << setw(20) << "Email";
//     cout << "| " << left << setw(15) << "Password";
//     cout << "| " << left << setw(12) << "Permission";
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n" << endl;

//     if (vClients.size() == 0)
//         cout << "\t\t\t\tNo Users Available In the System!";
//     else

//         for (clsUser user : vClients)
//         {

//             _printUserRecordLine(user);
//             cout << endl;
//         }

//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n" << endl;

//  }

// };
#pragma once
#include<iostream>
#include"../classes/clsUser.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class showUsersList:protected screen
{
static void _printUserRecordLine(clsUser c){
   cout << "| " << left << setw(15) <<c.getUserName() ;
    cout << "| " << left << setw(20) << c.getFname()+" "+c.getLname();
    cout << "| " << left << setw(12) << c.getPhone();
    cout << "| " << left << setw(20) << c.getEmial();
    cout << "| " << left << setw(15) << c.getPassword();
    cout << "| " << left << setw(12) << c.getPermission();
}
public:
static void ShowObjectUsersList()
{    

    vector <clsUser> vClients = clsUser::getUsers();
    string Title = "\t  Users List Screen";
    string SubTitle ="\t    (" + to_string(vClients.size()) + ") Users(s).";
    screen::drawScreenHeader(Title,SubTitle);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(20) << "Full Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(15) << "Password";
    cout << "| " << left << setw(12) << "Permission";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Users Available In the System!";
    else

        for (clsUser c : vClients)
        {

            _printUserRecordLine(c);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

};
