#include <iostream>
#include <string>

using namespace std;

// 1. 定义 Person（人员）基类
class Person {
protected: // 使用 protected 权限，使得派生类可以访问这些成员
    string name;   // 姓名
    int age;       // 年龄
    string gender; // 性别

public:
    // 构造函数
    Person(string n = "未知", int a = 0, string g = "未知") : name(n), age(a), gender(g) {}

    // 虚函数：显示人员信息（使用 virtual 方便后续的多态调用）
    virtual void display() const {
        cout << "【人员信息】" << endl;
        cout << "姓名: " << name << ", 年龄: " << age << ", 性别: " << gender << endl;
    }
};

// 2. 定义 Student（学生）类，继承自 Person
class Student : public Person {
protected:
    string studentId; // 学号
    string major;     // 专业

public:
    // 构造函数：需要调用基类 Person 的构造函数来初始化继承来的成员
    Student(string n, int a, string g, string sId, string m) 
        : Person(n, a, g), studentId(sId), major(m) {}

    // 重写显示函数
    void display() const override {
        cout << "【学生信息】" << endl;
        // 调用基类的属性显示
        cout << "姓名: " << name << ", 年龄: " << age << ", 性别: " << gender << endl;
        cout << "学号: " << studentId << ", 专业: " << major << endl;
    }
};

// 3. 定义 Graduate（研究生）类，继承自 Student
class Graduate : public Student {
private:
    string researchDir; // 研究方向
    string supervisor;  // 导师姓名

public:
    // 构造函数：需要调用直接基类 Student 的构造函数
    Graduate(string n, int a, string g, string sId, string m, string rDir, string sup)
        : Student(n, a, g, sId, m), researchDir(rDir), supervisor(sup) {}

    // 重写显示函数
    void display() const override {
        cout << "【研究生信息】" << endl;
        // 直接打印所有信息
        cout << "姓名: " << name << ", 年龄: " << age << ", 性别: " << gender << endl;
        cout << "学号: " << studentId << ", 专业: " << major << endl;
        cout << "研究方向: " << researchDir << ", 导师: " << supervisor << endl;
    }
};

// 4. 测试这些类
int main() {
    cout << "--- 实例化各个类的对象并测试 ---" << endl << endl;

    // 测试 Person 类
    Person p("张三", 45, "男");
    p.display();
    cout << "-------------------------" << endl;

    // 测试 Student 类
    Student s("李四", 20, "女", "20230001", "计算机科学与技术");
    s.display();
    cout << "-------------------------" << endl;

    // 测试 Graduate 类
    Graduate g("王五", 24, "男", "20230001G", "人工智能", "赵教授");
    g.display();
    cout << "-------------------------" << endl;

    // （进阶测试）多态性测试：使用基类指针指向派生类对象
    cout << "\n--- 多态性测试（基类指针调用） ---" << endl;
    Person* ptr;

    ptr = &s; // 指向 Student 对象
    ptr->display(); // 因为 display 是虚函数，这里会调用 Student 的 display

    cout << endl;

    ptr = &g; // 指向 Graduate 对象
    ptr->display(); // 会调用 Graduate 的 display

    return 0;
}