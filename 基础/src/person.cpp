#include <iostream>
#include <string>

class Person {
public:
    // 构造函数
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}

    // 成员函数
    std::string getName() const { return name; }         // 返回姓名
    std::string getAddress() const { return address; }   // 返回地址

private:
    std::string name;    // 姓名
    std::string address; // 地址
};

// 打印 Person 的信息
std::ostream &print(std::ostream &os, const Person &p) {
    os << "姓名: " << p.getName() << " 地址: " << p.getAddress();
    return os;
}

int main() {
    Person person1("Alice", "123 Main St");
    Person person2("Bob", "456 Park Ave");

    print(std::cout, person1) << std::endl;
    print(std::cout, person2) << std::endl;

    return 0;
}
