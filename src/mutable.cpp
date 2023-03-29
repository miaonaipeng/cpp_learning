//
// Created by naipe on 2023/3/29.
//
#include <iostream>

class Example {
public:
    Example(int value) : value_(value) {}

    int GetValue() const {
        // value_ 可以在 const 成员函数中被修改
        counter_++;
        return value_;
    }

private:
    int value_;
    mutable int counter_ = 0;
};

int main() {
    const Example example(42);
    std::cout << example.GetValue() << std::endl;// 输出 42
    std::cout << example.GetValue() << std::endl;// 输出 42
    std::cout << example.GetValue() << std::endl;// 输出 42
    std::cout << example.GetValue() << std::endl;// 输出 42
}
