#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"client.h"
#include"../screen.h"
#include"../globalUser.h"
#include"clsPerson.h"
#include"../classes/date.h"
#include"../classes/clsUser.h"
#include"../classes/clsClient.h"

class WhenTransfer:public screen
{
	struct transferData{
   string date;
   clsUser s;
   string fromAcountNumber;
   string toAcountNumber;
   string Amount;
   string fromBalance;
   string toBalance;
   };
	static void _printUserRecordLine(transferData d){
   cout << "| " << left << setw(35) <<d.date ;
   cout << "| " << left << setw(12) <<d.fromAcountNumber ;
   cout << "| " << left << setw(12) <<d.toAcountNumber ;
   cout << "| " << left << setw(12) <<d.Amount ;
   cout << "| " << left << setw(12) <<d.fromBalance ;
   cout << "| " << left << setw(12) <<d.toBalance ;
   cout << "| " << left << setw(12) << d.s.getUserName();
}
void static addDataToFile(string s){
    fstream MyFile;
    MyFile.open("transfer.text", ios::out|ios::app);//add
    if (MyFile.is_open())
        {
            MyFile<<s<<endl;
            MyFile.close();

        }
}
static string TransferdataFile(int amount,clsClient cFrom,clsClient cTo,string seperator="#//#"){
string s="";

s+=GetSystemDateTimeString()+seperator;
s+=cFrom.getAcountNumber()+seperator;
s+=cTo.getAcountNumber()+seperator;
s+=to_string(amount)+seperator;
s+=to_string(cFrom.getAcountBalance())+seperator;
s+=to_string(cTo.getAcountBalance())+seperator;
s+=globalUser.getUserName();
return s;
}
static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year,Hour,Minute,Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
	static transferData convertLinetToVector(string line,string seperator="#//#"){
    vector<string> v=SplitAboHadhood(line,seperator); 
    transferData t;
	t.date=v[0];
	t.s.setUserName(v[6]);
    t.Amount=v[3];
    t.fromAcountNumber=v[1];
    t.toAcountNumber=v[2];
    t.fromBalance=v[4];
    t.toBalance=v[5];
	return t;
} 


	static vector<transferData>loadTransferdataFromFile(){
    vector <transferData> v;

        fstream MyFile;
        MyFile.open("transfer.text", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

             clsUser Client;
            while (getline(MyFile, Line))
            {
              v.push_back(convertLinetToVector(Line));
            }

            MyFile.close();

        }

        return v;
}
public:
static void addDataWhenTransfer(int amount,clsClient cFrom,clsClient cTo){
addDataToFile(TransferdataFile(amount, cFrom, cTo));
}
static void ShowTransferLogList()
{  
      if (!CheckAccessRights(clsUser::enPermissions::logData))
        {
            return;// this will exit the function and it will not continue
        }
  
    vector <transferData> v =loadTransferdataFromFile();
    string Title = "\t  Log Transfer Log List Screen";
    string SubTitle ="\t    (" + to_string(v.size()) + ") Record(s).";
    screen::drawScreenHeader(Title,SubTitle);
    cout << "\n_____________________________________________________________________________________";
    cout << "___________________________________________________________________________________\n" << endl;

    cout << "| " << left << setw(35) << "Date/Time";
    cout << "| " << left << setw(12) << "S.Acct";
    cout << "| " << left << setw(12) << "D.Acct";
    cout << "| " << left << setw(12) << "Amount";
    cout << "| " << left << setw(12) << "S.Balance";
    cout << "| " << left << setw(12) << "d.Balance";
    cout << "| " << left << setw(12) << "s.Balance";
    cout << "| " << left << setw(12) << "User ";
    
    cout << "\n_____________________________________________________________________________________";
    cout << "___________________________________________________________________________________\n" << endl;

    if (v.size() == 0)
        cout << "\t\t\t\tNo Data Available In the System!";
    else

        for (transferData &c : v)
        {

            _printUserRecordLine(c);
            cout << endl;
        }

cout << "\n_____________________________________________________________________________________";
cout << "___________________________________________________________________________________\n" << endl;


}
};