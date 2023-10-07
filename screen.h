#pragma once
#include<iostream>
#include"globalUser.h"
#include"classes/date.h"
using namespace std;
class screen{
protected:
static void drawScreenHeader(string title,string subTitle=""){
    cout<<"\t\t\t\t\t__________________________________\n"
    <<"\n\t\t\t\t\t "<<title;
    if(subTitle!=""){
        cout << "\n\t\t\t\t\t  " << subTitle;
    }
    cout<<"\n\t\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t\t date : "<<dateNow();
    cout<<"\n\t\t\t\t\t user : "<<globalUser.getUserName()<<"\n";
    }

       static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
     
            if (!globalUser.checkPermission(Permission))
            {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
                cout << "\n\t\t\t\t\t______________________________________\n\n";
                return false;
            }
            else
            {
                return true;
            }

    }
};
