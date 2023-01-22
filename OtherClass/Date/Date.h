//
// Created by Zakhar Vashchenko on 07.10.22.
//

#ifndef LESSON5_DATE_H
#define LESSON5_DATE_H

#include "ctime"
#include "cmath"
#include <iostream>

using namespace std;

class Date {
public:
    Date();
    Date(int day, int month, int year);
    virtual ~Date();
    Date& operator = (const Date& obj);

    void showInfo() const;
    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;

    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;

    Date operator+(int n)const&;
    Date operator-(int n)const&;

    int operator-(const Date &obj1) const &;

    Date& operator += (int n);
    Date& operator -= (int n);


    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

    Date& operator -- ();
    Date operator -- (int n);
    Date& operator ++ ();
    Date operator ++ (int n);

    friend Date operator + (int n, Date lhs);
    friend Date operator - (int n, Date lhs);

    friend ostream& operator << (ostream& os, const Date& t);
    friend istream& operator >> (istream& is, Date& t);

private:
    int day;
    int month;
    int year;

    bool isLeapYear() const; //Проверка на високосный год
    bool isLeapYear(int year) const;
    int monthDays() const; //Количество дней по месяцу
    int monthDays(int month) const;
    void nextDate(); //Следующая дата
    void prevDate(); //Предыдущая дата
    bool valid() const; //Проверка даты на корректность
};


#endif //LESSON5_DATE_H
