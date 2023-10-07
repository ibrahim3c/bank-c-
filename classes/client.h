#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
string join(vector <string>v,char delim){
    string word="";
    for(auto d:v){
        word+=d+delim;
    }
    return word.substr(0,word.size()-1);
   }
vector<string> split(string s1,char delim)
{
     vector<string>v;
    string word;
    s1 += " ";
    for (char c : s1)
    {
        if (c!=delim)
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                v.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty())
    {
        v.push_back(word);
        word = "";
            }
    return v;
    }
vector<string> dividualString(string s1)
{
     vector<string>v;
    string word;
    s1 += " ";
    for (char c : s1)
    {
        if (!isspace(c))
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                v.push_back(word);
                word = "";
            }
        }
    }
    return v;
    }
string reveseWord(string s){
vector<string>v=dividualString(s);
 reverse(v.begin(), v.end());
 string ss=join(v,' ');
 return ss;
}
string replaceWord(string s,string oldValue,string newValue ){
    vector<string>v=dividualString(s);
    replace(v.begin(), v.end(), oldValue, newValue);
    string ss=join(v,' ');
    return ss;

}
string removePunctuations(string s){
    string word="";
    for(auto d:s){
        if(!ispunct(d))  word+=d;
    }
    return word;
}
struct client{
int number;
int pinCode;
string name;
string phoneNumber;
int accountBalace;
bool markDelete=false;
};
void printClient(client c){
    cout<<"number : "<<c.number<<endl;
    cout<<"pincode : "<<c.pinCode<<endl;
    cout<<"name : "<<c.name<<endl;
    cout<<"phonenumber : "<<c.phoneNumber<<endl;
    cout<<"acountbalance : "<<c.accountBalace<<endl;

}
client readClient(){
    client c;
    cout<<"enter account number :\n";
    cin>>c.number;
    cout<<"enter pinCode :\n";
    cin>>c.pinCode;
    cout<<"enter name :\n";
    cin>>c.name;
    cout<<"enter phone :\n";
    cin>>c.phoneNumber;
    cout<<"enter account balance :\n";
    cin>>c.accountBalace;
    return c;
}
client readClient3(int num){
    client c;
    c.number=num;
    cout<<"enter pinCode :\n";
    cin>>c.pinCode;
    cout<<"enter name :\n";
    cin>>c.name;
    cout<<"enter phone :\n";
    cin>>c.phoneNumber;
    cout<<"enter account balance :\n";
    cin>>c.accountBalace;
    return c;
}
client readClient2(){
    client c;
    cout<<"enter pinCode :\n";
    cin>>c.pinCode;
    cout<<"enter name :\n";
    cin>>c.name;
    cout<<"enter phone :\n";
    cin>>c.phoneNumber;
    cout<<"enter account balance :\n";
    cin>>c.accountBalace;
    return c;
}
string convertRecordToLine(client c,char separator='<'){
    string s="";
    s+=to_string(c.number)+separator;
    s+=to_string(c.pinCode)+separator;
    s+=(c.name)+separator;
    s+=c.phoneNumber+separator;
    s+=to_string(c.accountBalace);
    return s;

}

client convertLineToRecord(string s,char separator){
  client c;
  vector<string>v=split(s,separator);
c.number= stoi(v[0]);
c.name=v[2];
c.pinCode=stoi(v[1]);
c.phoneNumber=v[3];
c.accountBalace=stoi(v[4]);
return c;
}
void addClientToFile(client c,string File){
    fstream file;
    string s=convertRecordToLine(c);
    file.open(File,ios::out|ios::app);
    if(file.is_open()){
     file<<s<<"\n";
     file.close();
    }

}
void addManyClientToFile(string s){
    
    client c;
    char choice='y';
    do{
        c=readClient();
        addClientToFile(c,s);
        cout<<"the client has been added successfully,do you want to add another client  (y/n)";
        cin>>choice;
        tolower(choice);
    }while (choice =='y');
    
}

 client readFileToClient(string File,int &counter ){
    fstream f;
     counter=0;
     client c;
    f.open(File,ios::in);
    if(f.is_open()){
        string line;
        while(getline(f,line)){
            c=convertLineToRecord(line,'<');
            counter++;
        }
        f.close();
    }
    return c;
 }
 vector<client>readFileToVectorClient(string File){
    fstream f;
     vector<client> c;
    f.open(File,ios::in);
    if(f.is_open()){
        string line;
        while(getline(f,line)){
           c.push_back( convertLineToRecord(line,'<'));
            
        }
        f.close();
    }
    return c;
 }

void showClients(string file){
 client c;
 int count=0;
 c=readFileToClient(file,count);
cout<<"\t\t clisnt list ( "<<count<<" )\n";
cout<<"-------------------------------------------------------------------------------\n";
cout<<"|"<<setw(10)<<"acountnumber|"<<setw(10)<<"pincode|"
<<setw(15)<<"clientname|"<<setw(10)<<"phone"<<setw(10)<<"balance|\n";
cout<<"-------------------------------------------------------------------------------\n";
for(int i=0;i<count;i++){
cout<<"|"<<setw(10)<<c.number<<"|"<<setw(10)<<c.pinCode<<"|"
<<setw(15)<<c.name<<"|"<<setw(10)<<c.phoneNumber<<"|"<<setw(10)<<c.accountBalace<<"|\n";

}

}
void addManyClientToFile2(string s);
void showClients2(string file){
 
vector<client>v=readFileToVectorClient(file);
cout<<"\t\t clisnt list ( "<<v.size()<<" )\n";
cout<<"-------------------------------------------------------------------------------\n";
cout<<"|"<<setw(10)<<"acountnumber|"<<setw(10)<<"pincode|"
<<setw(15)<<"clientname|"<<setw(10)<<"phone"<<setw(10)<<"balance|\n";
cout<<"-------------------------------------------------------------------------------\n";
for(auto d:v){
cout<<"|"<<setw(10)<<d.number<<"|"<<setw(10)<<d.pinCode<<"|"
<<setw(15)<<d.name<<"|"<<setw(10)<<d.phoneNumber<<"|"<<setw(10)<<d.accountBalace<<"|\n";

}}
bool FindClientByAcountNumber(string file,int num,client &c){
    vector<client>v;
    bool isfound=false;
    v=readFileToVectorClient(file);
    for(client d:v){
       if( d.number==num) {
        c=d;
          isfound=true;
       }
    }
    return isfound;
}
bool isFoundAcountNumber(string file,int num){
    vector<client>v;
    bool isfound=false;
    v=readFileToVectorClient(file);
    for(client d:v){
       if( d.number==num) {
          isfound=true;
       }
    }
    return isfound;
}
int FoundAcountNumberPinAndReturnBalance(string file,int num,int pin){
    vector<client>v;
    bool isfound=false;
    v=readFileToVectorClient(file);
    for(client d:v){
       if( d.number==num&&d.pinCode==pin) {
          return d.accountBalace;
       }
    }
    return 0;
}
bool isFoundAcountNumberPinCode(string file,int num,int pin,client &c){
    vector<client>v;
    bool isfound=false;
    v=readFileToVectorClient(file);
    for(client d:v){
       if( d.number==num && d.pinCode==pin) {
          isfound=true;
          c=d;
       }
    }
    return isfound;
}
void addManyClientToFile2(string s){
    client c;
    char choice='y';
    do{
        cout<<"enter account number :\n";
         cin>>(c.number);
        if(isFoundAcountNumber(s,c.number))   cout <<"it is already exist !";
       else{  
        c=readClient3(c.number);
        addClientToFile(c,s);
        cout<<"the client has been added successfully,do you want to add another client  (y/n)";
        cin>>choice;
        tolower(choice);}
    }while (choice =='y');
    
}
bool FindClientByAcountNumberAndMark(string &file,int num,client &c){
    vector<client>v;
    bool isfound=false;
    v=readFileToVectorClient(file);
    for(client &d:v){
       if( d.number==num) {
        d.markDelete=true;
        c=d;
          isfound=true;
       }
    }
    return isfound;
}
void markClient(client &c){
    c.markDelete=true;
}


void updateFileToDelete(string File, vector<client> v, client c) {
    fstream file;
    string s = "";
    
    file.open(File, ios::out);
    if (file.is_open()) {
        for (auto d : v) {
            if (d.number == c.number ) {
                continue;  // تخطي السجل الذي يجب حذفه
            }
            s = convertRecordToLine(d);
            file << s << "\n";  // أضف سجل بفواصل بينها
        }
        
        file.close();
    }
}
void updateFileToDelete2(string File, vector<client> v, client c) {
    fstream file;
    string s = "";
    
    file.open(File, ios::out);
    if (file.is_open()) {
        for (auto &d : v) {
            if (d.number==c.number&&d.pinCode==c.pinCode){
                s = convertRecordToLine(c);
                 file << s<<"\n"; }
                 else   {
                    s = convertRecordToLine(d);
                 file << s<<"\n";
                 }}
        
        file.close();
    }
}

void replaceClientFromFile(string &File, vector<client> v,client c) {
    fstream file;
    string s = "";
    
    file.open(File, ios::out);
    if (file.is_open()) {
        for (auto &d : v) {
            if (d.markDelete == false)
                s = convertRecordToLine(d);
                file << s;
    }
        
        file.close();
    }
}

void deleteClient(string file,int num){
    client c;
    char choice;
  if( FindClientByAcountNumberAndMark(file,num,c)) {
    printClient(c);
    cout<<" \ndo u want to delete this client [y/n]\n";
    cin>>choice;
    if(choice=='y')
    {
    vector<client>v=readFileToVectorClient(file);
    updateFileToDelete(file,v,c);}
}
else cout<<"there is no client with number "<<num;
}
void findClient(string file,int num){
    client c;
    char choice;
  if( FindClientByAcountNumberAndMark(file,num,c)) {
    printClient(c);
    }
   else cout<<"there is no client with number "<<num;
}
void updateClient(string &file,int num){
    client c;
    char choice;
  if( FindClientByAcountNumberAndMark(file,num,c)) {
    printClient(c);
    cout<<" \ndo u want to update this client [y/n]\n";
    cin>>choice;
    if(choice=='y')
    {
        client cl=readClient2();
        cl.number=c.number;
    vector<client>v=readFileToVectorClient(file);
    replaceClientFromFile(file,v,cl);}
}
else  cout<<"there is no client with number "<<num;
}
void updateClient2(string &file,int num){
    client c;
    char choice;
  if( FindClientByAcountNumberAndMark(file,num,c)) {
    printClient(c);
    cout<<" \ndo u want to update this client [y/n]\n";
    cin>>choice;
    if(choice=='y')
    {
        client cl=readClient2();
        cl.number=c.number;
    vector<client>v=readFileToVectorClient(file);
    updateFileToDelete2(file,v,cl);}
}
else  cout<<"there is no client with number "<<num;
}
vector<string> SplitAboHadhood(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
           // if (sWord != "")
           // {
                vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }
     string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }