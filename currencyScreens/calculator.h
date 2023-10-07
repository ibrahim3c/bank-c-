#pragma once
#include<iostream>
#include<string>
#include"../classes/clsCurrency.h"
#include"../classes/client.h"
#include"../classes/inputValidate.h"
#include"../mainScreen.h"
#include"../screen.h"
using namespace std;
class currencyCalculator:protected screen
{
    static double convertToUSB(double amount,clsCurrency c){
        return amount/c.getRate();
    }
    static double convertToAnotherCurrency(double amount,clsCurrency c1,clsCurrency c2){
        double dolar=convertToUSB(amount,c1);
        if(c2.getCurrencyCode()=="USB"){
            return dolar;
        }
        else{
            (double)(dolar*c2.getRate());
        }
    }
  
public:
static void currencyCalculatorScreen()
    {

       screen::drawScreenHeader(" Currency Calculator Screen ");
       string code1;
       string code2;
       clsCurrency c1;
       clsCurrency c2;
       char choice;
      do{ 
          
          cout<<"Please enter Currency (from) code : ";cin>>code1;
           c1=clsCurrency::findByCode(code1);
           while(c1.isEmpty()){
                cout<<"not found pls enter another one : ";
                cin>>code1;
                c1=clsCurrency::findByCode(code1);
            }

            cout<<"Please enter Currency (to) code : ";cin>>code2;
            c2=clsCurrency::findByCode(code2);
            while(c2.isEmpty()){
                cout<<"not found pls enter another one : ";
                cin>>code2;
                c2=clsCurrency::findByCode(code2);
           }

           double amount;
           cout<<"enter amount to exchange :"; cin>>amount;
           //double ToDolar=convertToUSB(amount,c1);
           double ToDolar=amount/c1.getRate();
           c1.printCard();
            cout<<amount<<" "<<c1.getCurrencyCode()<<" = "
                <<ToDolar<<" "<<"USD \n";
        
            //double ToCurrency=convertToAnotherCurrency(amount,c1,c2);
            double ToCurrency=ToDolar*c2.getRate();
            c2.printCard();
            cout<<amount<<" "<<c1.getCurrencyCode()<<" = "
                <<ToCurrency<<" "<<c2.getCurrencyCode()<<"\n\n";
        
            cout<<"do u want to perform another calculation? [y/n] "; cin>>choice;
        }while(choice=='y'||choice=='Y');
       

    }


};