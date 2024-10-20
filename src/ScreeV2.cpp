#include<string>

Screen{
public:
    Screen& move(unsigned r, unsigned c);  // 移动光标
    Screen& set(char ch);  // 设置字符

private:
    unsigned cursor = 0;
    unsigned width = 0, height = 0;
    std::string contents;
};

// 移动光标
Screen& Screen::move(unsigned r, unsigned c) {
    cursor = r * width + c;
    return *this;  // 返回对象自身的引用
}

// 设置字符
Screen& Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;  // 返回对象自身的引用
}
