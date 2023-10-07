#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<vector>
using namespace std;
struct Date{
short day;
short month;
short year;
};
short dayOfWeekOrder(short year,short month,short day){
    short a=(14-month)/12;
    short y=year-a;
   short m=month+12*a-2;
   //gregotian//
   short d=(day+y+(y/4)+(y/400)-(y/100)+((31*m)/12))%7;
   return d;
}
string days_of_week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
struct period{
 Date start;
 Date end;
};
Date getDate(short day,short month,short year){
    Date d={day,month,year};
   return d;
}
Date getsystemDate(){
    Date d;
    time_t t=time(0);
    tm*now=localtime(&t);
    d.day=now->tm_mday;
    d.month=now->tm_mon+1;
    d.year=now->tm_year+1900;
    return d;
}
void printDate(Date d){
cout<<d.day<<"/"<<d.month<<"/"<<d.year;
}


bool isLeapYear2(int year){
    return year%4==0&&year%100!=0||year%400==0;
}
int days(int year){
    return isLeapYear2(year)?366:365;
}

int daysInMonth(int month,int year){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return month>0&&month<=12?month==2?isLeapYear2(year)?29:28:days[month-1]:0;
}
short daysInMonth2(short month,short year){
    short days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return month>0&&month<=12?month==2?isLeapYear2(year)?29:28:days[month-1]:0;
}
void convertTotalDaysToDate(short total,short year){
   
    for(int i=1;i<=12;i++){
        if(total>daysInMonth(i,year))  total-=daysInMonth(i,year);
        else {
            cout<<total<<"/"<<i<<"/"<<year;
            break;
        }
    }
}
void convertTotalDaysToDate2(short total,short year){
       int i=1;
    for(;total>daysInMonth(i,year);i++){
      total-=daysInMonth(i,year);
    }
     cout<<total<<"/"<<i<<"/"<<year;
}
Date dateAfterAdding(Date d,short total){       
    for(int i=0;i<total;i++){
      d.day++;
      if(d.day>daysInMonth(d.month,d.year))  {
        d.day=1;
        d.month++;
      }
      if(d.month>12){ 
        d.month=1; 
        d.year++;
      }
    }
    return d;
}
bool isLess2(Date d1,Date d2){
return d2.year>d1.year?true:d1.year>d2.year?false:d2.month>d1.month?true:d1.month>d2.month?false:d2.day>d1.day?true:d1.day>d2.day?false:false;
}
bool isLess(Date d1, Date d2) {
    return (d1.year < d2.year) ||
           (d1.year == d2.year && d1.month < d2.month) ||
           (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
}

bool isEqual(Date d1,Date d2){
    return d1.year==d2.year&&d1.month==d2.month&&d1.day==d2.day;
}
bool isLastDayInMonth(short day, short month, short year) {
    return day == daysInMonth(month, year);
}

bool isLastDayInMonth(Date &d) {
    return d.day == daysInMonth2(d.month, d.year);
}
Date increaseDateByOne(Date &d){
    d.day++;
    if(d.day>daysInMonth(d.month,d.year))  {
        d.month++;
        d.day=1;
    }
    if(d.month>12)  {
        d.year++;
        d.month=1;
    }
  return d;
}
Date increaseDateByOne2(Date &d){
   if(isLastDayInMonth(d)) {
    if(d.month==12) {
        d.month=1;
        d.day=1;
        d.year++;
    }
    else{
         d.day=1;
        d.month++;
    }
   }
   else{
    d.day++;
   }
  return d;
}
void increaseByxDays(Date &d,int days){
    for(int i=1;i<=days;i++){
        d.day++;
        if(d.day>daysInMonth(d.month,d.year)){
            d.month++;
            d.day=1;
        }
        if(d.month>12){
            d.year++;
            d.month=1;
        }
    }
}
void increaseByoneWeek(Date &d){
   increaseByxDays(d,7);
}
void increaseByxWeeks(Date&d,int weeks){
    increaseByxDays(d,7*weeks);
}
void increaseByoneMonth(Date &d){
    d.month++;
    if(d.month>12){
        d.year++;
        d.month=1;
    }

    // you should add this cuz we have for example 31/1/2000
    // when we add one month it will become 31/2/2000 --->it is wrong 
    // so we replace 31 to the correct days -->29
    int numOfDays=daysInMonth(d.month,d.year);
    if(d.day>numOfDays){
        d.day=numOfDays;
    }
}
void increaseByxMonths(Date &d,int months){
    for(int i=1;i<=months;i++){
    increaseByoneMonth(d);
    }
}
void increaseByoneYear(Date &d){
    d.year++;
}
void increaseByxYears(Date &d,int years){
    d.year+=years;
}
void increaseByoneDecade(Date &d){
    d.year+=10;
}
void increaseByxDecade(Date &d,int decades){
    d.year+=decades*10;
}
void increaseByoneCentury(Date &d){
d.year+=100;
}
void increaseByoneMillennium(Date &d){
    d.year+=1000;

}
void decreaseDateByOne(Date &d){
   if(d.day==1) {
    if(d.month==1) {
        d.month=12;
        d.day=daysInMonth(d.month,d.year);
        d.year--;
    }
    else{
        d.month--;
         d.day=daysInMonth(d.month,d.year);
    }
   }
   else{
    d.day--;
   }
 
}
void decreaseByxDays(Date &d,int days){
    for(int i=1;i<=days;i++){
        d.day--;
        if(d.day<1){
            d.month--;
            if(d.month<1){
            d.year--;
            d.month=12;
        }
            d.day=daysInMonth(d.month,d.year);
        }
        
    }
}
void decreaseByxDays2(Date &d,int days){
    for(int i=1;i<=days;i++){
        decreaseDateByOne(d);
    }
}
void decreaseByoneWeek(Date &d){
   decreaseByxDays(d,7);
}
void decreaseByxWeeks(Date&d,int weeks){
    decreaseByxDays(d,7*weeks);
}
void decreaseByoneMonth(Date &d){
    d.month--;
    if(d.month<1){
        d.year--;
        d.month=12;
    }

    // you should add this cuz we have for example 31/1/2000
    // when we add one month it will become 31/2/2000 --->it is wrong 
    // so we replace 31 to the correct days -->29
    int numOfDays=daysInMonth(d.month,d.year);
    if(d.day>numOfDays){
        d.day=numOfDays;
    }
}
void decreaseByxMonths(Date &d,int months){
    // we should save the day cuz in for loop 
    // we decrese by one so it will change day 
    // for example the day is 30 
    //when month ==2 the day will change to 29 or 28 :(
    int day=d.day;
    for(int i=1;i<=months;i++){
    decreaseByoneMonth(d);
    }
    d.day=day;
    int numOfDays=daysInMonth(d.month,d.year);
    if(d.day>numOfDays){
        d.day=numOfDays;
    }

    
}
void decreaseByoneYear(Date &d){
    d.year--;
}
void decreaseByxYears(Date &d,int years){
    d.year-=years;
}
void decreaseByoneDecade(Date &d){
    d.year-=10;
}
void decreaseByxDecade(Date &d,int decades){
    d.year-=decades*10;
}
void decreaseByoneCentury(Date &d){
d.year-=100;
}
void decreaseByoneMillennium(Date &d){
    d.year-=1000;

}
int dateToDays(Date d){
 int total=0;
 for(int i=1;i<=d.year;i++){
 total +=days(i);
 }
 for(int i=1;i<=d.month;i++){
    total+=daysInMonth(i,d.year);
 }
 total+=d.day;
 return total;

}
int diffDays2(Date d1,Date d2){
    cout<<"there is something wrong here:(\n";
    if(isLess(d1,d2)){
    return dateToDays(d2)-dateToDays(d1);
    }
    else return -1;
}
short diff(Date d1,Date d2){
    int diff=0;

    if(isLess(d2,d1)) return -1;
    if(isEqual(d1,d2)) return 0;
    while(isLess(d1,d2)){
        diff++;
        d1=increaseDateByOne(d1);
    }
    return diff;
}
int ageByDays(Date d){
    Date dNow=getsystemDate();
    return diffDays2(d,dNow);
}
short dayOfWeekOrder(Date d){
    short a=(14-d.month)/12;
    short y=d.year-a;
   short m=d.month+12*a-2;
   //gregotian//
   short order=(d.day+y+(y/4)+(y/400)-(y/100)+((31*m)/12))%7;
   return order;
}
bool isEndOfWeek(Date d){
   return dayOfWeekOrder(d)==6;
}
bool isWeekend(Date d){
   return dayOfWeekOrder(d)==6|| dayOfWeekOrder(d)==5; 
}
bool isBusinessDay(Date d){
   return !isWeekend(d); 
}
short daysUntilEndOfWeek(Date d){
    return 6-dayOfWeekOrder(d);
}
short daysUntilEndOfMonth(Date d){
    return daysInMonth(d.month,d.year)-d.day;
}
short totalDaysFromBeginning(Date d){
    short tDays=0;
    for(int i=1;i<d.month;i++){
        tDays+=daysInMonth(i,d.year);
    }
    return tDays+d.day;
}
short daysUntilEndOfYear(Date d){
    return days(d.year)-totalDaysFromBeginning(d);
}
void printDateWithName(Date d){
 cout<<days_of_week[dayOfWeekOrder(d)]<<", ";printDate(d);
}
int vocationPeriod(Date start,Date end){
    printDateWithName(start);
    cout<<endl;
    printDateWithName(end);
    cout<<endl;
    int actualVocation=0;
    for(int i=start.day;i<end.day;i++)
    { 
        increaseDateByOne(start);
       if(isWeekend(start)) continue;
       else  actualVocation++;
    }
    return actualVocation;
}
Date dateAfterVocation(Date start,int days){
    printDateWithName(start);
    cout<<endl;
    Date dateAfterVoc=start;
   int vocationdays=0;
    while(vocationdays<days)
    { 
        if(isBusinessDay(dateAfterVoc))  vocationdays++;
        increaseDateByOne(dateAfterVoc);
         
    }
    printDateWithName(dateAfterVoc);
    return dateAfterVoc;
}
bool isMore(Date d1,Date d2){
    return !isLess(d1,d2)&&!isEqual(d1,d2);
}
int compareDate(Date d1,Date d2){
    return isMore(d1,d2)?1:isEqual(d1,d2)?0:-1;
}
bool isOverlap2(period p1,period p2){
    return (isMore(p1.start,p2.start)&&isLess(p1.start,p2.end))||(isMore(p2.start,p1.start)&&isLess(p2.start,p1.end))
    ||(isEqual(p1.start,p2.start))||(isEqual(p1.end,p2.end));
}
bool isOverlap(period p1,period p2){
    return !(isMore(p1.start,p2.end)||isMore(p2.start,p1.end));
}
bool isOverlap3(period p1,period p2){
    return compareDate(p1.start,p2.end)==1||compareDate(p2.start,p1.end)==1;
}
int periodLength(period p){
    return diff(p.start,p.end);
}
bool isDateWithinPeriod(Date d,period p){
    return!(compareDate(d,p.start)==-1||compareDate(d,p.end)==1) ;

}
bool isDateWithinPeriod3(Date d,period p){
    bool x=(compareDate(d,p.start)==-1||compareDate(d,p.end)==1) ;
    return !x;
}
bool isDateWithinPeriod2(Date d,period p){
    period p1={d,d};
    return isOverlap(p1,p);

}
int countOverlapDays(period p1,period p2){
    int count=0;
if(isOverlap(p1,p2)){
    if(isDateWithinPeriod2(p2.start,p1)&&isDateWithinPeriod2(p2.end,p1)){
    count=diff(p2.start,p2.end);
    }
    else if(isDateWithinPeriod2(p2.start,p1)){
       count=diff(p2.start,p1.end);
    }
    }
    return count;
}

bool isValidPeiod(period p){
    return !(isMore(p.start,p.end));
 }
bool isValidDate(Date d){
    return d.month>12||d.month<0?0:d.day>daysInMonth(d.month,d.year)||d.day<0?0:1;
}
// vector<string>split(string s,char c){
// vector<string>v;
// string word="";
// for(auto &d:s){
//     if(d!=' '&&d!=c){
//        word+=d;
//     }
//     else if(!word.empty())
//     {
//        v.push_back(word);
//        word=" ";
//     }
// }
//      if(!word.empty())
//      {
//        v.push_back(word);
//        word=" ";
//      }
//      return v;
// }
Date stringToDate(string date){
    vector<string>v=split(date,'/');
    Date d;
    d.day=stoi(v[0]);
    d.month=stoi(v[1]);
    d.year=stoi(v[2]);
    return d;
}
string DateTostring(Date d){
    string word="";
    word+=to_string(d.day)+'/';
    word+=to_string(d.month)+'/';
    word+=to_string(d.year);
    return word;
}
static string dateNow(){
    Date d=getsystemDate();
    return DateTostring(d);
    
}
static string timeNow() {
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the time to a string
    std::string timeString = std::ctime(&currentTime);

    return timeString;
}