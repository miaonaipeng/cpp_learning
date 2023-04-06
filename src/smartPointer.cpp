//
// Created by 缪乃鹏 on 4/6/23.
//

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
    void print() {
        std::cout << "hello" << std::endl;
    }
};

int main() {
    //    {
    //        std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    //        ptr->print();
    //    }// 当ptr离开作用域时，MyClass的实例会被自动删除

    //    {
    //        std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    //        {
    //            std::shared_ptr<MyClass> ptr2 = ptr1;
    //        }// ptr2离开作用域，但ptr1仍然指向对象，因此对象不会被删除
    //    }    // 当ptr1离开作用域时，对象会被自动删除

    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr1 = ptr1;
    {
        std::shared_ptr<MyClass> ptr2 = weakPtr1.lock();
        if (ptr2) {
            std::cout << "weakPtr1 is still observing the object" << std::endl;
        }
    }
    ptr1.reset();
    std::shared_ptr<MyClass> ptr3 = weakPtr1.lock();
    if (!ptr3) {
        std::cout << "weakPtr1 is no longer observing the object" << std::endl;
    }

    std::cout << "End of the main function" << std::endl;

    return 0;
}
