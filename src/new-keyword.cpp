//
// Created by 缪乃鹏 on 4/1/23.
//
#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string &name, int age) : name_(name), age_(age) {}

    void introduce() {
        std::cout << "Hello, my name is " << name_ << " and I am " << age_ << " years old." << std::endl;
    }

private:
    std::string name_;
    int age_;
};

int main() {
    //    // 使用new为一个整数分配内存
    //    int *ptr = new int;
    //    *ptr = 42;// 通过指针ptr访问分配的内存并存储值
    //
    //    std::cout << "Value of *ptr: " << *ptr << std::endl;
    //
    //    // 使用new为一个整数数组分配内存
    //    int size = 5;
    //    int *arr = new int[size];
    //
    //    for (int i = 0; i < size; i++) {
    //        arr[i] = i + 1;
    //    }
    //
    //    // 输出数组的内容
    //    for (int i = 0; i < size; i++) {
    //        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    //    }
    //
    //    // 使用完后，释放内存
    //    delete ptr;
    //    delete[] arr;
    Person *p = new Person("Mike", 20);

    p->introduce();

    delete p;


    return 0;
}