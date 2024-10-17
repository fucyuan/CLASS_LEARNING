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

// 定义 read 函数：从输入流读取数据
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 定义 print 函数：将数据输出到流
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

// 定义 add 函数：将两个 Sales_data 对象合并
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;      // 创建副本
    sum.combine(rhs);          // 合并 rhs
    return sum;
}

// 主函数测试
int main() {
    Sales_data data1, data2;
    std::cout << "请输入两条交易记录: " << std::endl;
    read(std::cin, data1);
    read(std::cin, data2);
    
    Sales_data sum = add(data1, data2);
    print(std::cout, sum) << std::endl;

    return 0;
}
