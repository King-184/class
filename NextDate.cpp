#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return -1; // 无效月份
    }
}

void NextDate(int &year, int &month, int &day) {
    day++;
    
    int daysInCurrentMonth = daysInMonth(year, month);
    if (day > daysInCurrentMonth) {
        day = 1;
        month++;
        
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

int main() {
    // 测试用例
    int y, m, d;
    
    // 闰年2月
    y = 2024; m = 2; d = 28;
    NextDate(y, m, d);
    cout << "2024-2-28 的下一天是: " << y << "-" << m << "-" << d << endl;
    
    // 非闰年2月
    y = 2023; m = 2; d = 28;
    NextDate(y, m, d);
    cout << "2023-2-28 的下一天是: " << y << "-" << m << "-" << d << endl;
    
    return 0;
}
