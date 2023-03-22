//
// Created by naipe on 2023/3/22.
//
#include "basic.h"
#include "vector"
#include <iostream>
struct Entity {
    static int x;
    static int y;
    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};
// 这是非静态方法在编译时的真实样子。
static void Print(Entity e) {
    std::cout << e.x << ", " << e.y << std::endl;
}


void Function() {
    static int i = 0;// 第一次调用这个函数，i被初始化为0，然后对所有后续的调用，实际上不会创造一个全新的变量
    i++;
    std::cout << i << std::endl;
}

class Singleton {
private:
public:
    // 返回一个引用
    static Singleton &Get() {
        static Singleton instance;// 这里如果没有static，变量会被创建在栈上，运行后就销毁
        return instance;
    }
    void Hello() {}
};

int main() {

    Singleton::Get().Hello();


    std::cin.get();
    return 0;
}
