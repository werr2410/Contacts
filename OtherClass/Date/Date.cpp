//

#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() = default;

Date::Date() {
    auto* tim = new tm;
    time_t tt = time(nullptr);
    tim = localtime(&tt);
    
    this->day = tim->tm_mday;
    this->month = tim->tm_mon + 1;
    this->year = tim->tm_year + 1900;
}

void Date::showInfo() const {
    cout << day/10%10 << day%10 << '.' << month/10%10 << month%10 << '.' << year << endl;
}

Date &Date::operator=(const Date &obj) {
    this->day = obj.day;
    this->month = obj.month;
    this->year = obj.year;
    return *this;
}

bool Date::isLeapYear() const {
    if (year%4 != 0 || year%100 == 0 && year%400 != 0){
        return false;
    }
    return true;
}

int Date::monthDays() const {
    if( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(month == 2){
        if (isLeapYear())
            return 29;
        else
            return 28;
    }
    return 0;
}

void Date::nextDate() {
    if (month == 12 && day == 31){
        year++;
        month = 1;
        day = 1;
    }else if(day == monthDays()){
        day = 1;
        month++;
    }else
        day++;
}

void Date::prevDate() {
    if (month == 1 && day == 1){
        year--;
        month = 12;
        day = 31;
    }else if(day == 1){
        month--;
        day = monthDays();
    }else
        day--;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    if (day>=1 && day<=monthDays())
        Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    if (month>=1 && month<=12)
        Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

bool Date::valid() const {
    if (month>=1 && month<=12 && day>=1 && day<=monthDays()){
        return true;
    }
    return false;
}

bool Date::operator==(const Date &rhs) const {
    return day == rhs.day &&
           month == rhs.month &&
           year == rhs.year;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

bool Date::operator<(const Date &rhs) const {
    if (rhs.year > year) 
        return true;
    else if (rhs.year == year) {
        if (rhs.month > month) 
            return true;
        else if (rhs.month == month) {
            if (rhs.day > day)
                return true;
            else if (rhs.day == day)
                return false;
        }
    }

    return false;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

Date Date::operator+(int n) const &{
    Date tmp = *this; //Конструктор копирования
    for (int i = 0; i < n; ++i)
        tmp.nextDate();
    return tmp; //Конструктор копирования
}

Date Date::operator-(int n) const &{
    Date tmp = *this; //Конструктор копирования
    for (int i = 0; i < n; ++i)
        tmp.prevDate();
    return tmp; //Конструктор копирования
}

int Date::operator-(const Date &obj1) const &{
    if(obj1==*this)
        return 0;
    bool leftBigger = *this > obj1;
    int days=0;
    if(!leftBigger)
    {
        for(int i = getYear() +1; i <= obj1.getYear(); i++)
            if(isLeapYear(i))
                days+=366;
            else
                days+=365;

        for(int i = 1; i < getMonth(); i++)
            days-=monthDays(i);
        days-=day;

        for(int i = 1; i < obj1.getMonth(); i++)
            days+=monthDays(i);
        days+=obj1.day;
    }
    else
    {
        for(int i = obj1.getYear() +1; i <= getYear(); i++)
            if(isLeapYear(i))
                days+=366;
            else
                days+=365;

        for(int i = 1; i < obj1.getMonth(); i++)
            days-=monthDays(i);
        days-=obj1.day;

        for(int i = 1; i < getMonth(); i++)
            days+=monthDays(i);
        days+=day;
    }
    return fabs(days);
}

Date &Date::operator+=(int n) {
    for (int i = 0; i < n; ++i)
        this->nextDate();
    return *this; //Конструктор копирования
}

Date &Date::operator-=(int n) {
    for (int i = 0; i < n; ++i)
        this->prevDate();
    return *this; //Конструктор копирования
}

bool Date::isLeapYear(int year) const {
    if (year%4 != 0 || year%100 == 0 && year%400 != 0){
        return false;
    }
    return true;
}

int Date::monthDays(int month) const {
    if( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(month == 2){
        if (isLeapYear())
            return 29;
        else
            return 28;
    }
    return 0;
}

Date &Date::operator--() {
    prevDate();
    return *this;
}

Date Date::operator--(int n) {
    Date tmp = *this;
    this->prevDate();
    return tmp;
}

Date &Date::operator++() {
    nextDate();
    return *this;
}

Date Date::operator++(int n) {
    Date tmp = *this;
    this->nextDate();
    return tmp;
}

Date operator+(int n, Date lhs) {
    Date tmp = lhs;
    for (int i = 0; i < n; ++i) {
        tmp.nextDate();
    }
    return tmp;
}

Date operator-(int n, Date lhs) {
    Date tmp = lhs;
    for (int i = 0; i < n; ++i) {
        tmp.prevDate();
    }
    return tmp;
}

ostream &operator<<(ostream &os, const Date &t) {
    os << t.day/10 << t.day %10 << '.' << t.month/10 << t.month%10 << '.' << t.year;
    return os;
}

istream &operator>>(istream &is, Date &t) {
    do{
        cout << "dd mm yyyy: ";
        is >> t.day >> t.month >> t.year;
    }while(!t.valid());
    return is;
}
