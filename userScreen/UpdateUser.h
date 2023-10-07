#pragma once
#include<iostream>
#include"../classes/clsUser.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class UpdateUser:protected screen
{
    static void _readUserInfo (clsUser& c){
    string firstName;
    string lastName;
    string email;
    string phone;
    string password;
    cout << "\nEnter First Name: ";
    cin>>firstName;
    c.setFname(firstName);
    cout << "\nEnter LastName: ";
    cin>>lastName;
    c.setLname(lastName);
    cout << "\nEnter phone: ";
    cin>>phone;
    c.setPhone(phone);
    cout << "\nEnter Email: ";
    cin>>email;
    c.setEmial(email); 
    cout << "\nEnter password: ";
    cin>>password;
    c.setPassword(password);
    int p=_getPermissions();
    c.setPermission(p);
}
static int _getPermissions(){

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::List;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::Add;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::del;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::Update;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::Find;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::Transaction;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::ManageUsers;
        }
        cout << "\nLog Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::logData;
        }

        return Permissions;
}

public:
static void UpdateObjectUser(){
     screen::drawScreenHeader("Update User Screen ");
     string userName = "";
    cout << "\nPlease Enter user name: ";
    cin>> userName;
    while (!clsUser::IsUserExist(userName))
    {
        cout << "\n User Name does not exist, enter another one: ";
        cin>> userName;
    }

        clsUser User1 = clsUser::find(userName);

        User1.print();

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


    _readUserInfo(User1);

    clsUser::enSaveResult SaveResult;

    SaveResult = User1.save();

    switch (SaveResult)
    {
    case  clsUser::enSaveResult::succeed:
    {
        cout << "\n User Addeded Successfully :-)\n";
        User1.print();
        break;
    }
    case clsUser::enSaveResult::faild:
    {
        cout << "\nError user was not saved because it's Empty";
        break;

    }
    }
}}


};