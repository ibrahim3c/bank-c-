#include<iostream>
#include"classes/clsClient.h"
#include "classes/client.h"
#include"classes/inputValidate.h"
#include"mainScreen.h"
#include"login.h"
using namespace std;
int main(){
    // clsClient c=clsClient::find("A101");
    // c.print();
    // clsClient c=readClientInfo();

   // UpdateObjectClient();
   //addNewObjectClient();
  // DeleteObjectClient();
  //ShowObjectClientsList();
  //ShowTotalBalances();  
  //mainScreen::showMainScreen();
   while(true) {
    if(!Login::LoginScreen()){
        break;
    }
    }
}
