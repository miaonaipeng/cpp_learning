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

void draw(Shape *s) {// 函数重载
    s->draw();
}

void draw(Circle *c) {// 函数重载
    c->draw();
}

void draw(Rectangle *r) {// 函数重载
    r->draw();
}

int main() {
    Shape *s = new Shape();
    Circle *c = new Circle();
    Rectangle *r = new Rectangle();

    draw(s);// 调用Shape*类型的draw函数
    draw(c);// 调用Circle*类型的draw函数
    draw(r);// 调用Rectangle*类型的draw函数

    s = c;    // 基类指针指向派生类对象
    s->draw();// 调用Circle类型的draw虚函数

    s = r;    // 基类指针指向派生类对象
    s->draw();// 调用Rectangle类型的draw虚函数

    return 0;
}