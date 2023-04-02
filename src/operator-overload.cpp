//
// Created by 缪乃鹏 on 4/2/23.
//

#include "iostream"
class Complex {
private:
    double real_;
    double imag_;

public:
    Complex(double real, double imag) : real_(real), imag_(imag) {}

    Complex operator+(const Complex &other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }
    void print() const {
        std::cout << real_ << "+" << imag_ << "i" << std::endl;
    }
};

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}