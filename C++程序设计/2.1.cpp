#include <iostream>
#include <string>

using namespace std;

class Songer {
private:
    string name;       // 姓名
    int fans_count;    // 粉丝数
    static int count;  // 当前歌手人数 【静态数据成员】

public:
    // ① 构造函数：初始化 name 和 fans_count，并对 count 做增加操作
    Songer(string n = "无名氏", int f = 0) : name(n), fans_count(f) {
        count++;
        cout << "[构造] 歌手 " << name << " 加入，当前粉丝数: " << fans_count << endl;
    }

    // ② 复制构造函数
    Songer(const Songer& s) {
        name = s.name + " (克隆)";
        fans_count = s.fans_count;
        count++; // 复制出的新对象，总数也要加1
        cout << "[复制构造] 复制了歌手 " << name << endl;
    }

    // ④ 析构函数
    ~Songer() {
        count--; // 歌手对象销毁时，总人数减1
        cout << "[析构] 歌手 " << name << " 退出，当前���人数剩余: " << count << endl;
    }

    // ③ Set函数：修改粉丝数
    void setFansCount(int f) {
        fans_count = f;
        cout << name << " 的粉丝数更新为: " << fans_count << endl;
    }

    // ⑤ ShowCount函数：显示当前歌手的数量【静态成员函数】
    static void ShowCount() {
        cout << ">>> 统计: 当前共有 " << count << " 名歌手。 <<<" << endl;
    }

    // 声明友元函数，允许其访问 Songer 的私有成员
    friend void Pk(Songer &s1, Songer &s2);
};

// 静态数据成员必须在类外部初始化
int Songer::count = 0;

// （3）编写 Songer 类的友元函数：Pk
void Pk(Songer &s1, Songer &s2) {
    cout << "\n--- PK 开始: " << s1.name << " VS " << s2.name << " ---" << endl;
    if (s1.fans_count > s2.fans_count) {
        cout << "结果: " << s1.name << " 战胜 " << s2.name << "！" << endl;
    } else if (s1.fans_count < s2.fans_count) {
        cout << "结果: " << s2.name << " 战胜 " << s1.name << "！" << endl;
    } else {
        cout << "结果: " << s1.name << " 和 " << s2.name << " 打成平手！" << endl;
    }
    cout << "-----------------------------------" << endl;
}

// （4）主函数测试
int main() {
    // 测试静态成员函数，此时为0
    Songer::ShowCount();

    // 建立三个 Songer 类的对象
    Songer s1("张三", 100);
    Songer s2("李四", 120);
    Songer::ShowCount();

    // 测试复制构造函数
    Songer s3(s1);
    Songer::ShowCount();

    // 测试 Pk 友元函数
    Pk(s1, s2);

    // 测试 Set 函数修改粉丝数
    s1.setFansCount(150);
    
    // 再次 Pk
    Pk(s1, s2);
    Pk(s1, s3);

    return 0;
}