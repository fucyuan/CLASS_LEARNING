#include <iostream>
#include <string>

class Screen {
public:
    Screen() = default;
    Screen(unsigned w, unsigned h, char c);  // 构造函数，接受宽、高和字符

    // 成员函数
    Screen& move(unsigned r, unsigned c);  // 移动光标
    Screen& set(char ch);  // 设置字符
    Screen& display(std::ostream& os);  // 显示屏幕内容

private:
    unsigned cursor = 0;  // 光标位置
    unsigned width = 0, height = 0;  // 屏幕宽度和高度
    std::string contents;  // 屏幕内容，由字符组成的字符串
};

// 构造函数实现，初始化宽高和字符
Screen::Screen(unsigned w, unsigned h, char c)
    : width(w), height(h), contents(w * h, c) {}

// move函数实现，移动光标到指定行和列
Screen& Screen::move(unsigned r, unsigned c) {
    cursor = r * width + c;  // 计算光标位置
    return *this;  // 返回引用，支持链式调用
}

// set函数实现，在光标位置设置字符
Screen& Screen::set(char ch) {
    contents[cursor] = ch;  // 设置字符
    return *this;  // 返回引用，支持链式调用
}

// display函数实现，显示屏幕内容
Screen& Screen::display(std::ostream& os) {
    for (unsigned i = 0; i < height; ++i) {
        os << contents.substr(i * width, width) << std::endl;
    }
    return *this;  // 返回引用，支持链式调用
}

int main() {
    // 创建5x5的屏幕，初始内容为'X'
    Screen myScreen(5, 5, 'X');

    // 使用链式调用
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";

    // 单独调用display
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}
