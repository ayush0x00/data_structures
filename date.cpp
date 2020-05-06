#include <cassert>

class Date{
public:
  Date(int day, int month, int year); //constructor
  int Day(){return day_;}
  int Month(){return month_;}
  int Year(){return year_;}
  void Month(int month);
  void Year(int year);
  void Day(int day);
private:
  bool IsLeapYear(int year) ;//const says that member will not change the state of object
  int DaysInMonth(int month, int year) ;
  int day_{1};
  int month_{1};
  int year_{2000};
};

Date::Date(int day,int month,int year ){//passing year as initilizer list as it has no invariant chek
  Month(month);
  Year(year);
  Day(day);
}

void Date:: Day(int day){
  if(day>=1 && day<=DaysInMonth(Month(),Year())){
    day_=day;
  }
}
void Date::Month(int month){
  if(month>=1 and month<=12)
    month_=month;
}
void Date::Year(int year){
  year_=year;
}
bool Date::IsLeapYear(int year) {
  if (year%4==0 && year%100!=0)
    return true;
  else if (year%400==0)
    return true;
}
int Date::DaysInMonth(int month,int year) {
  if (month==2){
    return IsLeapYear(year)?29:28;
  }
  else if(month==4||month==6||month==9||month==11){
    return 30;
  }
  else{
    return 31;
  }
}

int main(){
  Date date(29,2,2020);
  assert(date.Day()==29);
  assert(date.Month()==2);
  assert(date.Year()==2020);
}
