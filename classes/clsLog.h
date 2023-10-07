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
#include"../classes/utile.h"

class Whenlog:public screen
{
	struct logData{
   string date;
   clsUser s;
   };
	static void _printUserRecordLine(logData d){
   cout << "| " << left << setw(35) <<d.date ;
    cout << "| " << left << setw(20) << d.s.getUserName();
    cout << "| " << left << setw(15) << d.s.getPassword();
    cout << "| " << left << setw(12) << d.s.getPermission();
}
void static addDataToFile(string s){
    fstream MyFile;
    MyFile.open("log.text", ios::out|ios::app);//add
    if (MyFile.is_open())
        {
            MyFile<<s<<endl;
            MyFile.close();

        }
}
static string dataFile(string seperator="#//#"){
string s="";
//s+=dateNow()+" - "+timeNow()+seperator;
s+=GetSystemDateTimeString()+seperator;
s+=globalUser.getUserName()+seperator;
s+=globalUser.getPassword()+seperator;
s+=to_string(globalUser.getPermission());
return s;
}
static string dataFile2(string seperator="#//#"){
string s="";
//s+=dateNow()+" - "+timeNow()+seperator;
s+=GetSystemDateTimeString()+seperator;
s+=globalUser.getUserName()+seperator;
s+=clsUtil::EncryptText(globalUser.getPassword())+seperator;
s+=to_string(globalUser.getPermission());
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
	static logData convertLinetToVector(string line,string seperator="#//#"){
    vector<string> v=SplitAboHadhood(line,seperator); 
    logData l;
	l.date=v[0];
	l.s.setUserName(v[1]);
	l.s.setPassword(v[2]);
	l.s.setPermission(stoi(v[3]));
	return l;
} 
	static logData convertLinetToVector2(string line,string seperator="#//#"){
    vector<string> v=SplitAboHadhood(line,seperator); 
    logData l;
	l.date=v[0];
	l.s.setUserName(v[1]);
	l.s.setPassword(clsUtil::DecryptText(v[2]));
	l.s.setPermission(stoi(v[3]));
	return l;
} 


	static vector<logData>loadLogdataFromFile(){
    vector <logData> v;

        fstream MyFile;
        MyFile.open("log.text", ios::in);//read Mode

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
static void addDataWhenLog(){
addDataToFile(dataFile());
}
static void ShowLogDataList()
{  
      if (!CheckAccessRights(clsUser::enPermissions::logData))
        {
            return;// this will exit the function and it will not continue
        }
  
    vector <logData> v =loadLogdataFromFile();
    string Title = "\t  Log Register List Screen";
    string SubTitle ="\t    (" + to_string(v.size()) + ") Record(s).";
    screen::drawScreenHeader(Title,SubTitle);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(35) << "Date/Time";
    cout << "| " << left << setw(20) << "UserName";
    cout << "| " << left << setw(15) << "Password";
    cout << "| " << left << setw(12) << "Permission";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (v.size() == 0)
        cout << "\t\t\t\tNo Data Available In the System!";
    else

        for (logData c : v)
        {

            _printUserRecordLine(c);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}
};