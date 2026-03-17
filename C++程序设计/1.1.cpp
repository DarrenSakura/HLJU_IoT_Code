#include <iostream>

using namespace std;

class Tree {
private:
    int ages; // 树龄

public:
    // 构造函数，默认初始树龄为 0
    Tree(int initialAge = 0) {
        ages = initialAge;
    }

    // 树长大的成员函数
    void grow(int years) {
        if (years > 0) {
            ages += years;
        }
    }

    // 显示树龄的成员函数
    void age() const {
        cout << "当前树龄为: " << ages << " 年" << endl;
    }
};

int main() {
    Tree myTree(5); // 初始树龄为 5
    myTree.age();   // 显示当前树龄
    
    cout << "树生长了 3 年..." << endl;
    myTree.grow(3); // 长大 3 年
    myTree.age();   // 再次显示树龄

    return 0;
}