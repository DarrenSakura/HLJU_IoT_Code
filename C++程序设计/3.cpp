#include <iostream>

using namespace std;

// 定义链表节点结构体
struct Node {
    int data;       // 数据域
    Node* next;     // 指针域

    // 节点的构造函数，方便初始化
    Node(int val) : data(val), next(nullptr) {}
};

// 定义链表类
class LinkedList {
private:
    Node* head; // 链表头指针

public:
    // 1. 初始化：构造函数
    LinkedList() {
        head = nullptr;
        cout << "[系统] 链表已初始化（创建空链表）。" << endl;
    }

    // 2. 建立：向链表末尾添加元素（尾插法）
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode; // 如果链表为空，新节点���为头节点
        } else {
            Node* current = head;
            // 找到链表的最后一个节点
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode; // 将新节点挂在最后
        }
    }

    // 辅助建立：批量从控制台输入创建链表
    void create(int n) {
        cout << "请输入 " << n << " 个整数来建立链表: ";
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            append(val);
        }
        cout << "[系统] 链表建立完成。" << endl;
    }

    // 3. 输出：遍历并打印链表所有元素
    void display() const {
        if (head == nullptr) {
            cout << "链表为空。" << endl;
            return;
        }
        
        cout << "当前链表内容: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // 4. 释放：手动清空链表并释放内存
    void release() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;       // 暂存当前节点
            current = current->next;    // 移动到下一个节点
            delete temp;                // 释放暂存的节点内存
        }
        head = nullptr; // 头指针置空，防止野指针
    }

    // 析构函数：对象销毁时自动调用释放功能
    ~LinkedList() {
        release();
        cout << "[系统] 链表内存已全部释放，对象安全析构。" << endl;
    }
};

int main() {
    // 1. 初始化链表
    LinkedList myList;
    myList.display();

    // 2. 建立链表（可以手动追加，也可以批量建立）
    cout << "\n--- 测试手动追加元素 ---" << endl;
    myList.append(10);
    myList.append(20);
    myList.append(30);
    
    // 3. 输出链表
    myList.display();

    cout << "\n--- 测试批量建立功能 ---" << endl;
    LinkedList list2;
    list2.create(3); // 提示输入3个数字
    list2.display();

    // 4. 程序结束时，析构函数会自动调用 release() 释放内存
    cout << "\n--- 程序准备退出，触发析构函数 ---" << endl;
    
    return 0;
}