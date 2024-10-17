#include <iostream>
#include <string>

class Sales_data {
public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}

    // 成员函数
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &rhs);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

    // 成员变量
private:
    std::string bookNo;      // 书籍编号
    unsigned units_sold = 0; // 销量
    double revenue = 0.0;    // 收入
};

// combine 成员函数定义：合并两个 Sales_data 对象的数据信息
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 打印 Sales_data 的信息
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << "ISBN: " << item.isbn() << " 销售数量: " << item.units_sold << " 收入: " << item.revenue;
    return os;
}

int main() {
    Sales_data data1("12345", 10, 20.5);
    Sales_data data2("12345", 5, 20.5);

    data1.combine(data2); // 合并 data2 到 data1
    print(std::cout, data1) << std::endl;

    return 0;
}
