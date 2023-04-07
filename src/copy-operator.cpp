//
// Created by 缪乃鹏 on 4/7/23.
//
#include <iostream>


class MyString {
public:
    // ...其他成员函数
    MyString(const char *src) {
        if (src == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(src) + 1];
            strcpy(str, src);
        }
    }
    // 拷贝赋值运算符，实现深拷贝
    MyString &operator=(const MyString &other) {
        if (this == &other) {
            return *this;
        }

        delete[] str;

        if (other.str == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }

        return *this;
    }
    
    char *str;
};

int main() {
    MyString s1("hello");
    MyString s2("world");

    s2 = s1;// 调用拷贝赋值运算符，将s1的值赋给s2

    // 输出结果应为"hello"
    std::cout << "s2: " << s2.str << std::endl;

    return 0;
}
