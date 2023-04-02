//
// Created by 缪乃鹏 on 4/2/23.
//

#include <iostream>

class MyClass {
public:
    // 使用explicit关键字标记构造函数，防止隐式转换
    explicit MyClass(int value) : value_(value) {}

    int getValue() const {
        return value_;
    }

private:
    int value_;
};

void printValue(const MyClass &obj) {
    std::cout << "Value: " << obj.getValue() << std::endl;
}

int main() {
    MyClass obj1(42);// 正确，显式构造对象
    printValue(obj1);

    // MyClass obj2 = 42;  // 错误，不允许隐式转换
    // printValue(42);     // 错误，不允许隐式转换

    MyClass obj3 = static_cast<MyClass>(42);// 正确，显式转换
    printValue(obj3);

    return 0;
}