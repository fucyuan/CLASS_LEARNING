#include <iostream>
#include <string>

class Screen {
public:
    Screen() = default;
    Screen(unsigned w, unsigned h);
    Screen(unsigned w, unsigned h, char c);
    void display() const;

private:
    unsigned width = 0, height = 0;
    std::string contents;
};

Screen::Screen(unsigned w, unsigned h)
    : width(w), height(h), contents(w * h, ' ') {}

Screen::Screen(unsigned w, unsigned h, char c)
    : width(w), height(h), contents(w * h, c) {}

void Screen::display() const {
    for (unsigned i = 0; i < height; ++i) {
        std::cout << contents.substr(i * width, width) << std::endl;
    }
}

class Sales_data {
public:
    double avg_price() const;

private:
    unsigned units_sold = 10;
    double revenue = 5.0;
};

inline double Sales_data::avg_price() const {
    if (units_sold != 0)
        return revenue / units_sold;
    else
        return 0;
}

int main() {
    Screen screen1(10, 5, '*');
    screen1.display();

    Sales_data data;
    std::cout << "Average price: " << data.avg_price() << std::endl;

    return 0;
}
