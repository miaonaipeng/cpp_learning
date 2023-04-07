#include "iostream"
#include "string"

//class String {
//private:
//    char *m_Buffer;
//    unsigned int m_Size;
//
//public:
//    String(const char *string) {
//        m_Size = strlen(string);
//        m_Buffer = new char[m_Size + 1];
//        memcpy(m_Buffer, string, m_Size + 1);
//    }
//    friend std::ostream &operator<<(std::ostream &stream, const String &string);
//    ~String() {
//        delete m_Buffer;
//    }
//    char &operator[](unsigned int index) {
//        return char;
//    }
//};
//
//// overload operator to print string
//
//std::ostream &operator<<(std::ostream &stream, const String &string) {
//    stream << string.m_Buffer;
//    return stream;
//}
//
//int main() {
//    String string = "cherno";
//    String second = string;
//    std::cout << string << std::endl;
//    std::cout << second << std::endl;
//
//    return 0;
//}

#include <cstring>

class MyString {
public:
    MyString(const char *src) {
        if (src == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(src) + 1];
            strcpy(str, src);
        }
    }
    // copy constructor to deep copy
    MyString(const MyString &other) {
        if (other.str == nullptr) {
            str = nullptr;
        } else {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    }

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
    // 其他成员函数

private:
    char *str;
};

void func() {
    MyString s1("hello");
    MyString s2(s1);// 浅拷贝，s1和s2的str指向同一块内存
}
// 当func()执行完毕后，s1和s2的析构函数都会被调用，释放相同的内存，导致双重释放的问题。

int main() {
    func();
    return 0;
}
