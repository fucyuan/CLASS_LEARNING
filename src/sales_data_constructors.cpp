#include <iostream>
#include <string>

class Sales_data {
public:
    // 默认构造函数
    // Sales_data() = default;
    // 构造函数，显式初始化成员变量
    Sales_data(const std::string &s = "", unsigned n = 0, double p = 0.0) 
        : bookNo(s), units_sold(n), revenue(p * n) { }

    // 带书籍编号的构造函数
    // Sales_data(const std::string &s) : bookNo(s) {}

    // 带书籍编号、销量、价格的构造函数
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    // 带输入流的构造函数
    Sales_data(std::istream &is) {
        read(is, *this);  // 使用 read 函数从输入流读取数据
    }

    // 成员函数
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &rhs);
    double avg_price() const;

    // 友元函数
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// combine 成员函数定义：合并两个 Sales_data 对象的数据信息
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 返回平均价格
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

// 定义 read 函数：从输入流读取 Sales_data 的信息
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 定义 print 函数：将 Sales_data 的信息输出到流
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

// 定义 add 函数：将两个 Sales_data 对象合并
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// 主函数测试
int main() {
    Sales_data book1("12345");
     Sales_data book4;
    Sales_data book2("67890", 10, 15.99);
    Sales_data book3(std::cin);  // 从输入流构造
    // print(std::cout, book1) << std::endl;
    print(std::cout, book2) << std::endl;
    print(std::cout, book3) << std::endl;

    return 0;
}
