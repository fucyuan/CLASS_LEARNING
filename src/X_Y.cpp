#include <iostream>

// 前向声明 class Y，因为 class X 中使用了 Y 的指针
class Y;

class X {
public:
    Y* yPtr;  // X 包含一个指向 Y 的指针
    X(Y* y) : yPtr(y) {}  // 构造函数，接受指向 Y 的指针
};

class Y {
public:
    X xObj;  // Y 包含一个 X 对象
    Y() : xObj(this) {}  // 构造函数，创建 X 对象并将自身指针传递给 X
};

int main() {
    Y y;  // 创建一个 Y 的对象
    std::cout << "Y contains an X object, and X contains a pointer to Y." << std::endl;
    return 0;
}
