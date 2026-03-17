#include <iostream>

using namespace std;

// 编写使用选择法排序的函数模板
template <class T>
void mySort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // 记录最小元素的索引
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        // 如果找到更小的元素，则交换
        if (minIndex != i) {
            T temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// 辅助打印函数模板
template <class T>
void printArray(T a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- 测试整型数组排序 ---" << endl;
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "排序前: ";
    printArray(intArray, intSize);
    mySort(intArray, intSize);
    cout << "排序后: ";
    printArray(intArray, intSize);

    cout << "\n--- 测试浮点型数组排序 ---" << endl;
    double doubleArray[] = {3.14, 1.59, 2.65, 5.89, 0.45};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    cout << "排序前: ";
    printArray(doubleArray, doubleSize);
    mySort(doubleArray, doubleSize);
    cout << "排序后: ";
    printArray(doubleArray, doubleSize);

    return 0;
}