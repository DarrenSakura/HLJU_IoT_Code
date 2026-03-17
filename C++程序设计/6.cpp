#include <iostream>

using namespace std;

// ================= 类的定义与实现 =================

class Tree // 树
{
public:
    virtual void show();
    virtual ~Tree();
};

Tree::~Tree() {
    cout << "析构一个树对象!" << endl;
}

void Tree::show() {
    cout << "树是非常重要的一种数据结构！" << endl;
}

class Binary_Tree : public Tree // 二叉树
{
public:
    virtual void show();
    virtual ~Binary_Tree();
};

Binary_Tree::~Binary_Tree() {
    cout << "析构一个二叉树对象!" << endl;
}

void Binary_Tree::show() {
    cout << "二叉树每个结点至多有两棵子树，且有左右之分！"
