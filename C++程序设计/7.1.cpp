#include <iostream>

using namespace std;

// 集合类模板 Set 定义
template <class T> 
class Set {
private:
    T* value;   // 指向动态数组的指针
    int size;   // 集合中实际元素的个数
    int length; // 动态数组的最大容量

public:
    // 构造函数
    Set(int len = 50) {
        length = len;
        size = 0;
        value = new T[length];
    }

    // 拷贝构造函数
    Set(const Set<T>& A) {
        length = A.length;
        size = A.size;
        value = new T[length];
        for (int i = 0; i < size; ++i) {
            value[i] = A.value[i];
        }
    }

    // 析构函数
    ~Set() {
        delete[] value;
    }

    // 重载"="使集合对象可以整体赋值
    Set<T>& operator=(const Set<T>& r) {
        if (this == &r) return *this; // 防止自赋值

        delete[] value; // 释放原有内存
        length = r.length;
        size = r.size;
        value = new T[length];
        for (int i = 0; i < size; ++i) {
            value[i] = r.value[i];
        }
        return *this;
    }

    // 判断集合中是否包含元素v
    bool isExist(T v) const {
        for (int i = 0; i < size; ++i) {
            if (value[i] == v) {
                return true;
            }
        }
        return false;
    }

    // 修改动态数组value的大小
    void Resize(int len) {
        if (len <= 0) return;
        T* newValue = new T[len];
        // 拷贝原有数据，防止越界取较小值
        int copySize = (size < len) ? size : len; 
        for (int i = 0; i < copySize; ++i) {
            newValue[i] = value[i];
        }
        delete[] value;
        value = newValue;
        length = len;
        size = copySize;
    }

    // 向集合中添加一个元素
    void add(T v) {
        if (isExist(v)) {
            return; // 集合要求元素不重复
        }
        // 如果容量已满，则扩容为原来的 2 倍
        if (size >= length) {
            Resize(length == 0 ? 10 : length * 2);
        }
        value[size] = v;
        size++;
    }

    // 重载"+"求两个集合对象的并集
    Set<T> operator+(const Set<T>& r) {
        // 创建一个新集合，初始容量为两集合当前容量之和
        Set<T> temp(this->length + r.length);
        
        // 先把当前集合的元素全部加入
        for (int i = 0; i < this->size; ++i) {
            temp.add(this->value[i]);
        }
        // 再把另一个集合的元素加入，add() 内部自带去重功能
        for (int i = 0; i < r.size; ++i) {
            temp.add(r.value[i]);
        }
        return temp;
    }

    // 输出集合中所有元素
    void display() const {
        cout << "{ ";
        for (int i = 0; i < size; ++i) {
            cout << value[i] << (i < size - 1 ? ", " : "");
        }
        cout << " }" << endl;
    }

    // 返回集合的大小（实际元素个数）
    int getSize() const { return size; }

    // 返回动态数组value的大小（容量）
    int getLength() const { return length; }
};

// ================= 主函数测试 =================
int main() {
    cout << "--- 集合 S1 ---" << endl;
    Set<int> s1(5);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(2); // 测试重复元素
    cout << "S1: ";
    s1.display();
    cout << "S1 元素个数: " << s1.getSize() << ", 数组容量: " << s1.getLength() << endl;

    cout << "\n--- 集合 S2 ---" << endl;
    Set<int> s2;
    s2.add(3); // 测试与 S1 重复的元素
    s2.add(4);
    s2.add(5);
    cout << "S2: ";
    s2.display();

    cout << "\n--- 集合并集 S3 = S1 + S2 ---" << endl;
    Set<int> s3 = s1 + s2;
    cout << "S3: ";
    s3.display();
    cout << "S3 元素个数: " << s3.getSize() << ", 数组容量: " << s3.getLength() << endl;

    cout << "\n--- 集合赋值测试 S4 = S3 ---" << endl;
    Set<int> s4;
    s4 = s3;
    cout << "S4: ";
    s4.display();

    cout << "\n--- 测试 Resize (缩小容量截断数据) ---" << endl;
    s4.Resize(2);
    cout << "S4 (截断后): ";
    s4.display();

    return 0;
}