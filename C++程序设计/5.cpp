#include <iostream>
#include <string>

using namespace std;

class Songer {
private:
    string name;       // 姓名
    int fans_count;    // 粉丝数
    static int count;  // 当前歌手人数

public:
    // 构造函数
    Songer(string n = "无名氏", int f = 0) : name(n), fans_count(f) {
        count++;
    }

    // 复制构造函数
    Songer(const Songer& s) {
        name = s.name;
        fans_count = s.fans_count;
        count++;
    }

    // 析构函数
    ~Songer() {
        count--;
    }

    // ------------------- 运算符重载开始 -------------------

    // 1. 重载“+”运算符（成员函数）：实现 s1 + 100
    // 返回一个新的 Songer 对象，保持原有对象不变，符合“+”的常规逻辑
    Songer operator+(int num) const {
        return Songer(this->name, this->fans_count + num);
    }

    // 2. 将“>”运算符重载为成员函数：比较 s1 > s2
    bool operator>(const Songer& s2) const {
        return this->fans_count > s2.fans_count;
    }

    // 4. 将前置“++”运算符重载为成员函数：实现 ++s1 (粉丝加10)
    // 返回自身的引用
    Songer& operator++() {
        this->fans_count += 10;
        return *this;
    }

    // 3. 将“==”运算符重载为友元函数：比较 s1 == s2
    friend bool operator==(const Songer& s1, const Songer& s2);

    // 5. 将后置“++”运算符重载为友元函数：实现 s1++ (粉丝加10)
    // 注意：后置++必须带一个 int 类型的哑元参数用于占位区分
    friend Songer operator++(Songer& s, int);

    // 6. 【选做】重载“<<”运算符：实现 cout << s1
    friend ostream& operator<<(ostream& os, const Songer& s);

    // ------------------- 运算符重载结束 -------------------
};

// 静态数据成员初始化
int Songer::count = 0;

// 3. 友元函数实现：==
bool operator==(const Songer& s1, const Songer& s2) {
    return s1.fans_count == s2.fans_count;
}

// 5. 友元函数实现：后置++ (s1++)
// 特点：先返回原来的值，再让原来的对象增加
Songer operator++(Songer& s, int) {
    Songer temp = s;       // 记录原来的状态
    s.fans_count += 10;    // 对象本身的粉丝数增加10
    return temp;           // 返回增加前的状态
}

// 6. 友元函数实现：<< (输出流重载)
ostream& operator<<(ostream& os, const Songer& s) {
    os << "【歌手】姓名: " << s.name << "\t粉丝数: " << s.fans_count;
    return os;
}

// ================= 主函数测试 =================
int main() {
    // 创建初始歌手
    Songer s1("周杰伦", 1000);
    Songer s2("林俊杰", 900);
    Songer s3("陈奕迅", 1000);

    // 测试 6: cout << s1
    cout << "--- 初始状态 ---" << endl;
    cout << "s1 -> " << s1 << endl;
    cout << "s2 -> " << s2 << endl;
    cout << "s3 -> " << s3 << endl;

    // 测试 1: s1 + 100
    cout << "\n--- 测试重载 + ---" << endl;
    Songer s4 = s2 + 100; // 林俊杰粉丝加100
    cout << "执行 s4 = s2 + 100 后: " << endl;
    cout << "s2 -> " << s2 << " (原对象不变)" << endl;
    cout << "s4 -> " << s4 << " (新对象)" << endl;

    // 测试 2: s1 > s2
    cout << "\n--- 测试重载 > ---" << endl;
    if (s1 > s2) {
        cout << "s1 的粉丝数 大于 s2 的粉丝数" << endl;
    } else {
        cout << "s1 的粉丝数 不大于 s2 的粉丝数" << endl;
    }

    // 测试 3: s1 == s2
    cout << "\n--- 测试重载 == ---" << endl;
    if (s1 == s3) {
        cout << "s1 的粉丝数 等于 s3 的粉丝数" << endl;
    } else {
        cout << "s1 的粉丝数 不等于 s3 的粉丝数" << endl;
    }

    // 测试 4: 前置 ++
    cout << "\n--- 测试前置 ++ ---" << endl;
    cout << "执行 ++s1 之���: " << s1 << endl;
    Songer s5 = ++s1; // 粉丝数加10，并返回加10后的对象
    cout << "执行 ++s1 之后: " << s1 << endl;
    cout << "赋值给 s5 的值: " << s5 << endl;

    // 测试 5: 后置 ++
    cout << "\n--- 测试后置 ++ ---" << endl;
    cout << "执行 s2++ 之前: " << s2 << endl;
    Songer s6 = s2++; // 粉丝数加10，但返回的是加10之前的对象
    cout << "执行 s2++ 之后: " << s2 << endl;
    cout << "赋值给 s6 的值(应为旧值): " << s6 << endl;

    return 0;
}