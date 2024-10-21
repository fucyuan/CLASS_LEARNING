#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    // 7.5.1 构造函数初始值列表
    // 默认构造函数
    Student() : name("Unnamed"), id(0), grade(0.0) { }

    // 带参数的构造函数
    Student(std::string name, int id, double grade) 
        : name(name), id(id), grade(grade) { }

    // 7.5.2 委托构造函数
    Student(int id) : Student("Unnamed", id, 0.0) { }

    // 7.5.3 默认构造函数的作用
    // 可以自动生成默认构造函数（如果不需要可以手动定义）

    // 7.3.2 返回*this的成员函数
    Student& setGrade(double newGrade) {
        grade = newGrade;
        return *this;
    }

    // 7.2 访问控制与封装
    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << std::endl;
    }

    // 7.5.6 宇宙面值常量类
    static const int maxStudents = 1000;  // 表示最大学生数量

private:
    // 成员变量
    std::string name;
    int id;
    double grade;

    // 7.3.1 类成员再探
    // 类中的其他类型成员可以是对象、指针等
    static int totalStudents;  // 静态成员表示总学生数

    // 7.4.1 名字查找与类的作用域
public:
    static int getTotalStudents() { return totalStudents; }
};

// 静态成员变量的定义
int Student::totalStudents = 0;

int main() {
    // 使用默认构造函数
    Student s1;
    s1.display();

    // 使用带参数的构造函数
    Student s2("Alice", 123, 92.5);
    s2.display();

    // 使用委托构造函数
    Student s3(456);
    s3.display();

    // 修改成绩并展示
    s3.setGrade(90.0).display();

    // 输出静态成员
    std::cout << "Total students allowed: " << Student::maxStudents << std::endl;

    return 0;
}
