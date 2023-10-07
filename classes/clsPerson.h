#pragma once
#include<iostream>
#include<string>
using namespace std;
class person{
  string fname;
  string lname;
  string email;
  string phone;
  public:
  person(string fname,string lname,string email,string phone){
    this->fname=fname;
    this->lname=lname;
    this->email=email;
    this->phone=phone;
  }
  person(){}
  void setFname(string fname){
    this->fname=fname;
  }
  void setLname(string lname){
    this->lname=lname;
  }
  void setEmial(string email){
    this->email=email;
  }
  void setPhone(string phone){
    this->phone=phone;
  }
  string getFname(){
    return this->fname;
  }
  string getLname(){
    return this->lname;
  }
  string getEmial(){
    return this->email;
  }
  string getPhone(){
    return this->phone;
  }
};