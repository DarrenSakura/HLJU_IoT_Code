#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// ================= 1. 学生类 Student =================
class Student {
private:
    string Num;    // 学号
    string name;   // 姓名
    string sex;    // 性别
    double score;  // 成绩

public:
    // ① 默认（无参）构造函数
    Student() : Num("000"), name("未命名"), sex("未知"), score(0.0) {}

    // ② 有参构造函数
    Student(string num, string n, string s, double sc) : Num(num), name(n), sex(s), score(sc) {}

    // ③ 复制构造函数
    Student(const Student& other) {
        Num = other.Num;
        name = other.name;
        sex = other.sex;
        score = other.score;
    }

    // ④ 设置信息函数
    void setInfo(string num, string n, string s, double sc) {
        Num = num;
        name = n;
        sex = s;
        score = sc;
    }

    // ⑤ 显示信息函数
    void display() const {
        cout << "学号: " << Num << "\t姓名: " << name 
             << "\t性别: " << sex << "\t成绩: " << score << endl;
    }

    // 获取学号和成绩（为排序和查询提供接口）
    string getNum() const { return Num; }
    double getScore() const { return score; }
    string getName() const { return name; }
    string getSex() const { return sex; }
};

// ================= 2. 学生信息控制类 StudentControl =================
class StudentControl {
private:
    // ① 选用 B. vector<Student> vecStu; (向量容器) 获得加5分
    vector<Student> vecStu; 
    // ② 学生个数
    int num; 

public:
    // ① 构造函数
    StudentControl() : num(0) {}

    // ② 从文件中读取学生信息存储到 vector
    void loadFromFile(const char* filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "[提示] 文件 " << filename << " 不存在或无法打开，将从空记录开始。\n";
            return;
        }
        vecStu.clear();
        string stuNum, n, s;
        double sc;
        while (inFile >> stuNum >> n >> s >> sc) {
            vecStu.push_back(Student(stuNum, n, s, sc));
        }
        num = vecStu.size();
        inFile.close();
        cout << "[系统] 成功从文件加载了 " << num << " 条学生记录。\n";
    }

    // ③ 显示所有学生信息
    void display() const {
        if (vecStu.empty()) {
            cout << "当前没有学生记录。\n";
            return;
        }
        cout << "\n--- 学生信息列表 (共 " << num << " 人) ---\n";
        for (const auto& stu : vecStu) {
            stu.display();
        }
        cout << "-----------------------------------\n";
    }

    // ④ 键盘输入若干学生信息
    void input() {
        int count;
        cout << "请输入要录入的学生人数: ";
        cin >> count;
        for (int i = 0; i < count; ++i) {
            string stuNum, n, s;
            double sc;
            cout << "请输入第 " << (i + 1) << " 个学生的 学号 姓名 性别 成绩 (空格分隔): ";
            cin >> stuNum >> n >> s >> sc;
            vecStu.push_back(Student(stuNum, n, s, sc));
            num++;
        }
        cout << "[系统] 录入成功！\n";
    }

    // ⑤ 对学生信息按成绩排序 (降序)
    void sortScores() {
        // 使用 Lambda 表达式定义排序规则：按成绩从大到小
        sort(vecStu.begin(), vecStu.end(), [](const Student& a, const Student& b) {
            return a.getScore() > b.getScore();
        });
        cout << "[系统] 按成绩排序完成！\n";
    }

    // ⑥ 把学生信息写入文件
    void writeToFile(const char* filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "[错误] 无法打开文件进行写入！\n";
            return;
        }
        for (const auto& stu : vecStu) {
            outFile << stu.getNum() << " " << stu.getName() << " " 
                    << stu.getSex() << " " << stu.getScore() << "\n";
        }
        outFile.close();
        cout << "[系统] 成功将 " << num << " 条记录保存至文件 " << filename << "。\n";
    }

    // ==== 补充功能：增加、删除、修改、查询 ====
    void addStudent(const Student& s) {
        vecStu.push_back(s);
        num++;
        cout << "[系统] 添加成功！\n";
    }

    void deleteStudent(string targetNum) {
        for (auto it = vecStu.begin(); it != vecStu.end(); ++it) {
            if (it->getNum() == targetNum) {
                vecStu.erase(it);
                num--;
                cout << "[系统] 成功删除学号为 " << targetNum << " 的学生。\n";
                return;
            }

