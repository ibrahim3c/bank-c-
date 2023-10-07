#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"client.h"
#include"clsPerson.h"
#include"utile.h"
using namespace std;
class clsUser:public person{
enum enMode{emptyMode=0,updateMode=1,addNew=2};
string userName;
string password;
int permissions;
enMode mode;
static clsUser convertLintToObjectUser2(string line,string seperator="#//#"){
   vector<string> v=SplitAboHadhood(line,seperator);
   return clsUser(enMode::updateMode,v[0],v[1],v[2],v[3],v[4],clsUtil::DecryptText(v[5]),stoi(v[6]));
} 
static clsUser convertLintToObjectUser(string line,string seperator="#//#"){
   vector<string> v=SplitAboHadhood(line,seperator);
   return clsUser(enMode::updateMode,v[0],v[1],v[2],v[3],v[4],v[5],stoi(v[6]));
} 
static clsUser getEmptyObject(){
    return clsUser(enMode::emptyMode,"","","","","","",0);
}
 void update(){
    vector<clsUser>v=loadUsersFromFile();
    for(clsUser &d:v){
      if(d.userName==this->userName) {
        d=*this;
        break;
      }
    }
    saveUsersToFile(v);
}
void addDataToFile(string s){
    fstream MyFile;
    MyFile.open("users.text", ios::out|ios::app);//add
    if (MyFile.is_open())
        {
            MyFile<<s<<endl;
            MyFile.close();

        }
}
// static vector<clsUser>loadUsersFromFile(){
//     vector <clsUser> vClients;

//         fstream MyFile;
//         MyFile.open("users.text", ios::in);//read Mode

//         if (MyFile.is_open())
//         {

//             string Line;

//              clsUser Client;
//             while (getline(MyFile, Line))
//             {
//               vClients.push_back(convertLintToObjectUser(Line));
//             }

//             MyFile.close();

//         }

//         return vClients;
// }
static string convertUserObjectToFile2(clsUser c,string sepertor="#//#"){
string s="";
s+=c.getFname()+sepertor;
s+=c.getLname()+sepertor;
s+=c.getEmial()+sepertor;
s+=c.getPhone()+sepertor;
s+=c.userName+sepertor;
s+=(clsUtil::EncryptText(c.password))+sepertor;
s+=to_string(c.permissions);
return s;
}
static string convertUserObjectToFile(clsUser c,string sepertor="#//#"){
string s="";
s+=c.getFname()+sepertor;
s+=c.getLname()+sepertor;
s+=c.getEmial()+sepertor;
s+=c.getPhone()+sepertor;
s+=c.userName+sepertor;
s+=c.password+sepertor;
s+=to_string(c.permissions);
return s;
}
 void saveUsersToFile( vector<clsUser>v){
        fstream MyFile;
        MyFile.open("users.text", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser &d : v)
            {
                MyFile << convertUserObjectToFile(d) << endl;

            }

            MyFile.close();

        }
}
void add_new(){
addDataToFile(convertUserObjectToFile(*this)); 
}
public:
enum enPermissions{All=-1,List=1,Add=2,del=4,Update=8,Find=16,Transaction=32,ManageUsers=64,logData=128,currency=256};
clsUser(enMode mode, string fname,string lname,string email,string phone,string userName,string password,int permissions):person(fname,lname,email,phone)
{
    this->userName=userName;
    this->password=password;
    this->permissions=permissions;
    this->mode=mode;
}
clsUser(){}
string getUserName(){
    return this->userName;
}
string getPassword(){
    return this->password;
}
int getPermission(){
    return this->permissions;
}

void setUserName(string username){
    this->userName=username;
}
void setPassword(string password){
    this->password=password;
}
void setPermission(int permission){
    this->permissions=permission;
}
bool isEmpty(){
    return this->mode==enMode::emptyMode;
}
enMode getMode(){
    return this->mode;
}
void print(){
    cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << this->getFname();
        cout << "\nLastName    : " << this->getLname();
        cout << "\nFull Name   : " << this->getFname()+" "+this->getLname();
        cout << "\nEmail       : " << this->getEmial();
        cout << "\nPhone       : " << this->getPhone();
        cout << "\nUserName : " << this->userName;
        cout << "\nPassword    : " << this->password;
        cout << "\n___________________\n";
}
static clsUser find(string userName){
    fstream file;
    file.open("users.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsUser c=convertLintToObjectUser(line);
          if(c.userName==userName) return c;
        }
        file.close();
    }
    return getEmptyObject();
}
static clsUser find(string userName,string password){
    fstream file;
    file.open("users.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsUser c=convertLintToObjectUser(line);
          if(c.userName==userName&&c.password==password) return c;
        }
        file.close();
    }
    return getEmptyObject();
}
enum enSaveResult{faild=0,succeed=1};
enSaveResult save(){
    switch (this->mode){
        case enMode::emptyMode:
            {return enSaveResult::faild;}
        case enMode::updateMode:
        {  
              update();
            return enSaveResult::succeed;
            break;
        }
        case enMode::addNew:{
            add_new();
            this->mode=enMode::updateMode;
            return enSaveResult::succeed;
        }
    }
}

static bool IsUserExist(string username)
{

        clsUser clsUser = find(username);
        return (!clsUser.isEmpty());
    }
static bool IsUserExistToLog(string username,string password)
{

        clsUser clsUser = find(username,password);
        return (!clsUser.isEmpty());
    }
//clsUser(enMode mode, string fname,string lname,string email,string phone,string userName,string password,int permissions):person(fname,lname,email,phone)

static  clsUser GetAddNewUserObject(string name){
     return clsUser(enMode::addNew,"","","","",name,"",0);
    }
bool Delete(){
   vector<clsUser>v=loadUsersFromFile();
    fstream MyFile;
        MyFile.open("users.text", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser &d : v)
            {
                if(d.userName==this->userName) continue;
               else{ MyFile << convertUserObjectToFile(d) << endl;}

            }

            MyFile.close();

        } 
  *this=getEmptyObject();
    return true;
}
static vector<clsUser> getUsers(){
    return loadUsersFromFile();
}
static vector<clsUser>loadUsersFromFile(){
    vector <clsUser> vClients;

        fstream MyFile;
        MyFile.open("users.text", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

             clsUser Client;
            while (getline(MyFile, Line))
            {
              vClients.push_back(convertLintToObjectUser(Line));
            }

            MyFile.close();

        }

        return vClients;
}
bool checkPermission(enPermissions p) {
    if (this->permissions == enPermissions::All) return true;
    if ((this->permissions & p) == p) return true;
    return false;
}


};