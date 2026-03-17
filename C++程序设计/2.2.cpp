#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

void Date::input() {
    cout << "请输入出生年份: ";
    cin >> year;
    cout << "请输入出生月份: ";
    cin >> month;
    cout << "请输入出生日期: ";
    cin >> day;
}

void Date::display() const {
    cout << year << "年" << month << "月" << day << "日";
}