#include<iostream>
#include"../classes/utile.h"
using namespace std;
int main(){
    string s="ibrahim";
    string d=clsUtil::EncryptText(s);
    cout<<d<<endl;
    cout<<clsUtil::DecryptText(d);
}