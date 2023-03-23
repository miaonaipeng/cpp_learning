//
// Created by naipe on 2023/3/23.
//

#include <iostream>
using namespace std;

class Shape {// 基类
public:
    virtual void draw() {// 虚函数
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {// 派生类
public:
    void draw() override {// 覆盖虚函数
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {// 派生类
public:
    void draw() override {// 覆盖虚函数
        cout << "Drawing a rectangle" << endl;
    }
};


int main() {
    Shape *ptr; // 基类类型的指针
    Circle c;   // 派生类对象
    Rectangle r;// 派生类对象

    ptr = &c;   // 指向圆形对象
    ptr->draw();// 调用圆形对象的draw函数

    ptr = &r;   // 指向矩形对象
    ptr->draw();// 调用矩形对象的draw函数

    return 0;
}