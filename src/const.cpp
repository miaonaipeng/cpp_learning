//
// Created by naipe on 2023/3/23.
//
#include "iostream"
using namespace std;

//引用使用的场景，通常用来修饰形参

class Demo {
    int x;

public:
    void set_data(int a);//非const成员函数
    int get_data() const;//const成员函数
};


int main() {
    const int MAX_AGE = 90;

    int *const a = new int;
    *a = 0;

    cout << *a << endl;
    delete a;

    Demo d1;              //非const对象
    d1.set_data(10);      //可以调用非const成员函数
    cout << d1.get_data();//可以调用const成员函数

    const Demo d2{};//const对象
    // d2.set_data(20);      //错误，不能调用非const成员函数
    cout << d2.get_data();//可以调用const成员函数

    return 0;
}
