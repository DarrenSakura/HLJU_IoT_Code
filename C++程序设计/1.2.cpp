#include <iostream>
#include <string>

using namespace std;

// 定义日期类 Date
class Date {
private:
    int year;
    int month;
    int day;

public:
    // 构造函数
    Date(int y = 1970, int m = 1, int d = 1) : year(y), month(m), day(d) {}

    // 录入日期
    void input() {
        cout << "请输入出生年份: ";
        cin >> year;
        cout << "请输入出生月份: ";
        cin >> month;
        cout << "请输入出生日期: ";
        cin >> day;
    }

    // 显示日期
    void display() const {
        cout << year << "年" << month << "月" << day << "日";
    }
};

// 定义人员类 People
class People {
private:
    string num;     // 编号
    string name;    // 姓名
    Date birth;     // 生日 (Date 类内嵌子对象)
    string id;      // 身份证号

public:
    // 录入人员信息
    void input() {
        cout << "--- 录入人员信息 ---" << endl;
        cout << "请输入编号: ";
        cin >> num;
        cout << "请输入姓名: ";
        cin >> name;
        
        // 调用内嵌对象的输入函数
        birth.input(); 
        
        cout << "请输入身份证号: ";
        cin >> id;
    }

    // 显示人员信息
    void display() const {
        cout << "\n--- 人员信息显示 ---" << endl;
        cout << "编号: " << num << endl;
        cout << "姓名: " << name << endl;
        cout << "生日: ";
        birth.display(); // 调用内嵌对象的显示函数
        cout << endl;
        cout << "身份证号: " << id << endl;
    }
};

int main() {
    People person;
    
    // 录入信息
    person.input();
    
    // 显示信息
    person.display();

    return 0;
}