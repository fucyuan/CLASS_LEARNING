#include <iostream>
#include <string>

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) { }

    // Explicit constructors prevent implicit conversions
    explicit Sales_data(const std::string &s) : bookNo(s) { }
    explicit Sales_data(std::istream &is) { is >> bookNo; }

    // Member function to combine sales data
    Sales_data& combine(const Sales_data &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    
    std::string isbn() const { return bookNo; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data item("0-123-45678-9", 5, 25.99);  // Create a Sales_data object
    std::string null_book = "9-999-99999-9";
    
    // The following line will now cause a compilation error due to the explicit constructor
    // item.combine(null_book);  // Error: no matching function for call

    // Instead, we must explicitly construct a Sales_data object from the string
    item.combine(Sales_data(null_book));  // OK: explicit construction
    
    std::cout << "Combined bookNo: " << item.isbn() << std::endl;

    return 0;
}
