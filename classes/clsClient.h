#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"client.h"
#include"clsPerson.h"
#include"utile.h"
using namespace std;
class clsClient:public person{
enum enMode{emptyMode=0,updateMode=1,addNew=2};
string acountNumber;
string pinCode;
double acountBalance;
enMode mode;
static clsClient convertLintToObjectDecryption(string line,string seperator="#//#"){
   vector<string> v=SplitAboHadhood(line,seperator);
   return clsClient(enMode::updateMode,v[0],v[1],v[2],v[3],v[4],clsUtil::DecryptText(v[5]),stoi(v[6]));
} 
static clsClient convertLintToObject(string line,string seperator="#//#"){
   vector<string> v=SplitAboHadhood(line,seperator);
   return clsClient(enMode::updateMode,v[0],v[1],v[2],v[3],v[4],v[5],stoi(v[6]));
} 
static clsClient getEmptyObject(){
    return clsClient(enMode::emptyMode,"","","","","","",0);
}
 void update(){
    vector<clsClient>v=loadClientsFromFile();
    for(clsClient &d:v){
      if(d.acountNumber==this->acountNumber) {
        d=*this;
        break;
      }
    }
    saveClientsToFile(v);
}
void addDataToFile(string s){
    fstream MyFile;
    MyFile.open("clients.text", ios::out|ios::app);//add
    if (MyFile.is_open())
        {
            MyFile<<s<<endl;
            MyFile.close();

        }
}
static vector<clsClient>loadClientsFromFile(){
    vector <clsClient> vClients;

        fstream MyFile;
        MyFile.open("clients.text", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

             clsClient Client;
            while (getline(MyFile, Line))
            {
              vClients.push_back(convertLintToObject(Line));
            }

            MyFile.close();

        }

        return vClients;
}
static string convertClientObjectToFileEncryption(clsClient c,string sepertor="#//#"){
string s="";
s+=c.getFname()+sepertor;
s+=c.getLname()+sepertor;
s+=c.getEmial()+sepertor;
s+=c.getPhone()+sepertor;
s+=c.getAcountNumber()+sepertor;
s+=(clsUtil::EncryptText(c.getPinCode()))+sepertor;
s+=to_string(c.getAcountBalance());
return s;
}
static string convertClientObjectToFile(clsClient c,string sepertor="#//#"){
string s="";
s+=c.getFname()+sepertor;
s+=c.getLname()+sepertor;
s+=c.getEmial()+sepertor;
s+=c.getPhone()+sepertor;
s+=c.getAcountNumber()+sepertor;
s+=c.getPinCode()+sepertor;
s+=to_string(c.getAcountBalance());
return s;
}
 void saveClientsToFile( vector<clsClient>v){
        fstream MyFile;
        MyFile.open("clients.text", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsClient &d : v)
            {
                MyFile << convertClientObjectToFile(d) << endl;

            }

            MyFile.close();

        }
}
void add_new(){
addDataToFile(convertClientObjectToFile(*this)); 
}
public:
clsClient(enMode mode, string fname,string lname,string email,string phone,string acountNumber,string pinCode,float acountBalance):person(fname,lname,email,phone)
{
    this->acountBalance=acountBalance;
    this->pinCode=pinCode;
    this->acountNumber=acountNumber;
    this->mode=mode;
}
clsClient(){}
string getAcountNumber(){
    return this->acountNumber;
}
float getAcountBalance(){
    return this->acountBalance;
}
string getPinCode(){
    return this->pinCode;
}
void setAcountBalance(double balance){
    this->acountBalance=balance;
}
void setPinCode(string pinCode){
    this->pinCode=pinCode;
}
bool isEmpty(){
    return this->mode==enMode::emptyMode;
}
enMode getMode(){
    return this->mode;
}
void print(){
    cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << this->getFname();
        cout << "\nLastName    : " << this->getLname();
        cout << "\nFull Name   : " << this->getFname()+" "+this->getLname();
        cout << "\nEmail       : " << this->getEmial();
        cout << "\nPhone       : " << this->getPhone();
        cout << "\nAcc. Number : " << this->acountNumber;
        cout << "\nPassword    : " << this->pinCode;
        cout << "\nBalance     : " << this->acountBalance;
        cout << "\n___________________\n";
}
static clsClient find(string acountNumber){
    fstream file;
    file.open("clients.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsClient c=convertLintToObject(line);
          if(c.acountNumber==acountNumber) return c;
        }
        file.close();
    }
    return getEmptyObject();
}
static clsClient find(string acountnumber,string pincode){
    fstream file;
    file.open("clients.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsClient c=convertLintToObject(line);
          if(c.acountNumber==acountnumber&&c.pinCode==pincode) return c;
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

static bool IsClientExist(string AccountNumber)
{

        clsClient Client1 = find(AccountNumber);
        return (!Client1.isEmpty());
    }
static  clsClient GetAddNewClientObject(string acountNumber){
     return clsClient(enMode::addNew,"","","","",acountNumber,"",0);
    }
bool Delete(){
   vector<clsClient>v=loadClientsFromFile();
    fstream MyFile;
        MyFile.open("clients.text", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsClient &d : v)
            {
                if(d.acountNumber==this->acountNumber) continue;
               else{ MyFile << convertClientObjectToFile(d) << endl;}

            }

            MyFile.close();

        } 
  *this=getEmptyObject();
    return true;
}
static vector<clsClient> getClients(){
    return loadClientsFromFile();
}
static double GetTotalBalances(){
  vector<clsClient>v=loadClientsFromFile();
  double totalBalance=0;
  for(clsClient &d:v){
    totalBalance+=d.getAcountBalance();
  }  
  return totalBalance;
}
void printClientCard(){
    cout<<"Client Card:\n";
    cout<<"______________________________________\n"
        <<"full Name  :"<<this->getFname()<<" "<<this->getLname()<<"\n"
        <<"Acc.Number :"<<this->acountNumber<<"\n"
        <<"Balance    :"<<this->acountBalance<<"\n"
        <<"______________________________________\n";
}

};