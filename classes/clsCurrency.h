#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"client.h"
#include"utile.h"
using namespace std;
class clsCurrency{
enum enMode{emptyMode=0,updateMode=1};
string country;
string currencyCode;
string currencyName;
float rate;
enMode mode;
static clsCurrency convertLintToObjectCurrency(string line,string seperator="#//#"){
   vector<string> v=SplitAboHadhood(line,seperator);
   return clsCurrency(enMode::updateMode,v[0],v[1],v[2],stod(v[3]));
} 
static clsCurrency getEmptyObject(){
    return clsCurrency(enMode::emptyMode,"","","",0);
}
 void update(){
    vector<clsCurrency>v=loadCurrenciesFromFile();
    for(clsCurrency &d:v){
      if(d.getCurrencyCode()==this->currencyCode) {
        d=*this;
        break;
      }
    }
    saveCurrencyToFile(v);
}

static string convertCurrencyObjectToFile(clsCurrency c,string sepertor="#//#"){
string s="";
s+=c.getCountry()+sepertor;
s+=c.getCurrencyCode()+sepertor;
s+=c.getCurrencyName()+sepertor;
s+=to_string(c.getRate());
return s;
}
 void saveCurrencyToFile( vector<clsCurrency>v){
        fstream MyFile;
        MyFile.open("currencies.text", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency &d : v)
            {
                MyFile << convertCurrencyObjectToFile(d) << endl;

            }

            MyFile.close();

        }
}

public:
enum enPermissions{All=-1,List=1,Add=2,del=4,Update=8,Find=16,Transaction=32,ManageUsers=64,logData=128};
clsCurrency(enMode mode,string country,string currencyCode,string currencyName,float rate)
{
    this->country=country;
    this->currencyCode=currencyCode;
    this->currencyName=currencyName;
    this->rate=rate;
    this->mode=mode;
}
clsCurrency(){}
string getCountry(){
    return this->country;
}
string getCurrencyCode(){
    return this->currencyCode;
}
string getCurrencyName(){
    return this->currencyName;
}
float getRate(){
    return this->rate;
}

void UpdateRate(float rate){
    this->rate=rate;
    update();
}
bool isEmpty(){
    return this->mode==enMode::emptyMode;
}
enMode getMode(){
    return this->mode;
}
// void print(){
//     cout << "\nUser Card:";
//         cout << "\n___________________";
//         cout << "\nFirstName   : " << this->getFname();
//         cout << "\nLastName    : " << this->getLname();
//         cout << "\nFull Name   : " << this->getFname()+" "+this->getLname();
//         cout << "\nEmail       : " << this->getEmial();
//         cout << "\nPhone       : " << this->getPhone();
//         cout << "\nUserName : " << this->userName;
//         cout << "\nPassword    : " << this->password;
//         cout << "\n___________________\n";
// }
static clsCurrency findByCode(string code){
    fstream file;
    file.open("currencies.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsCurrency c=convertLintToObjectCurrency(line);
          if(toLowerCase(c.currencyCode)==toLowerCase(code)) return c;
        }
        file.close();
    }
    return getEmptyObject();
}
static clsCurrency findByCountry(string country){
    fstream file;
    file.open("currencies.text",ios::in); // read mode
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        clsCurrency c=convertLintToObjectCurrency(line);
          if(toLowerCase(c.country)==toLowerCase(country)) return c;
        }
        file.close();
    }
    return getEmptyObject();
}

static bool IsCurrencyExistByCode(string currencyCode)
{
        clsCurrency c = findByCode(currencyCode);
        return (!c.isEmpty());
    }
static bool IsCurrencyExistByCounter(string country)
{
        clsCurrency c = findByCountry(country);
        return (!c.isEmpty());
    }

static vector<clsCurrency> getCurrencies(){
    return loadCurrenciesFromFile();
}
static vector<clsCurrency>loadCurrenciesFromFile(){
    vector <clsCurrency> vClients;

        fstream MyFile;
        MyFile.open("currencies.text", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
              vClients.push_back(convertLintToObjectCurrency(Line));
            }

            MyFile.close();

        }

        return vClients;
}
void printCard(){
    cout<<"Currency Card :\n"
        <<"--------------------------------\n"
        <<"Country   :"<<this->country<<"\n"
        <<"Code      :"<<this->currencyCode<<"\n"
        <<"Name      :"<<this->currencyName<<"\n"
        <<"Rate(1$)      :"<<this->rate<<"\n"
        <<"--------------------------------\n";
}
static string toLowerCase(const string& input) {
    string result = input;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

};