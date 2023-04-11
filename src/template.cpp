//
// Created by 缪乃鹏 on 4/11/23.
//
#include "iostream"

// template function
template<typename T>
T add(T a, T b) {
    return a + b;
}

// class template
template<typename T>
class Box {
public:
    explicit Box(T content) : content_(content) {}
    T getContent() const {
        return content_;
    }

private:
    T content_;
};

int main() {
    //    int a = 2, b = 3;
    //    double c = 2.0, d = 3.5;
    //    std::cout << "int add: " << add(a, b) << std::endl;   // 输出: int add: 5
    //    std::cout << "double add: " << add(c, d) << std::endl;// 输出: double add: 5.5

    Box<int> intBox(42);
    Box<std::string> stringBox("hello world!");
    std::cout << "intBox content: " << intBox.getContent() << std::endl;      // 输出: intBox content: 42
    std::cout << "stringBox content: " << stringBox.getContent() << std::endl;// 输出: stringBox content: Hello, World!

    return 0;
}