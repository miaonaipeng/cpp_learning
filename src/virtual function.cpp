//
// Created by naipe on 2023/3/23.
//

#include <iostream>
using namespace std;

// 定义一个抽象类Shape，作为一个接口
class Shape {
public:
    // 定义一个纯虚函数draw
    virtual void draw() = 0;
};

// 定义一个抽象类Color，作为另一个接口
class Color {
public:
    // 定义一个纯虚函数fill
    virtual void fill() = 0;
};

// 定义一个派生类Circle，实现Shape和Color两个接口

class Circle : public Shape, public Color {
public:
    int radix;

    void draw() override {
        cout << "Drawing a circle" << endl;
    }

    void fill() override {
        cout << "Filling the circle with red color" << endl;
    }
};


int main() {
    // 创建一个Circle对象
    Circle c;
    // 调用draw和fill函数
    c.draw();
    c.fill();
    return 0;
}