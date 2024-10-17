#include <iostream>
#include <string>

class Person {
public:
    // 构造函数
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}

    // 成员函数
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

    // 友元函数：读取和打印
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);

private:
    std::string name;
    std::string address;
};

// 定义 read 函数：从输入流读取 Person 的信息
std::istream &read(std::istream &is, Person &p) {
    std::getline(is, p.name);     // 读取姓名
    std::getline(is, p.address);  // 读取地址
    return is;
}

// 定义 print 函数：将 Person 的信息输出到流
std::ostream &print(std::ostream &os, const Person &p) {
    os << "姓名: " << p.getName() << "\n地址: " << p.getAddress();
    return os;
}

int main() {
    Person person1, person2;
    
    std::cout << "请输入第一个人的姓名和地址（每行输入一项）:" << std::endl;
    read(std::cin, person1);  // 读取第一个人的信息

    std::cout << "请输入第二个人的姓名和地址（每行输入一项）:" << std::endl;
    read(std::cin, person2);  // 读取第二个人的信息
    
    std::cout << "\n输出第一个人的信息：" << std::endl;
    print(std::cout, person1) << std::endl;  // 输出第一个人的信息

    std::cout << "\n输出第二个人的信息：" << std::endl;
    print(std::cout, person2) << std::endl;  // 输出第二个人的信息

    return 0;
}
