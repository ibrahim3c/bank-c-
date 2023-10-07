#pragma once
#include<iostream>
#include<limits>
//#include"date.h"
using namespace std;
class input_validate{
public:
template <class t>
static bool isNUmberBetween(t num,t num1,t num2){
  return num2>num1?(num>=num1&&num<=num2):(num<=num1&&num>=num2);
}
// static bool isDateBetween(Date d,Date d1,Date d2){
//     return isLess(d1,d2)?!(isMore(d,d2)||isLess(d,d1)):!(isMore(d,d1)||isLess(d,d2));
// }
static int readIntNumber( string error="invalid") {
    int x;
    while (!(cin >> x)) {
        cin.clear(); // إعادة تفعيل الإدخال
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تجاهل الباقي في السطر
        cout << error << endl; // طباعة رسالة الخطأ
    }
    return x;
}
static double readDoubleNumber( string error="invalid") {
    double num;
    while (!(cin >> num)) {
        cin.clear(); // إعادة تفعيل الإدخال
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تجاهل الباقي في السطر
        cout << error << endl; // طباعة رسالة الخطأ
    }
    return num;
}
static float readFloatNumber( string error="invalid") {
    float num;
    while (!(cin >> num)) {
        cin.clear(); // إعادة تفعيل الإدخال
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تجاهل الباقي في السطر
        cout << error << endl; // طباعة رسالة الخطأ
    }
    return num;
}
static int readIntNumberBetween(int num1,int num2,string error="invalid"){
    int num;
  while ((!(cin >> num))||!(isNUmberBetween(num,num1,num2))) {
        cin.clear(); // إعادة تفعيل الإدخال
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تجاهل الباقي في السطر
        cout << error << endl; // طباعة رسالة الخطأ
    }
    return num;
}

// static bool is_valid_date(Date d){
//     return isValidDate(d);
// }
};