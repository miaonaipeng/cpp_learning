//
// Created by 缪乃鹏 on 4/2/23.
//
class MyClass {
public:
    MyClass &setX(int x) {
        this->x = x;
        return *this;
    }

    MyClass &setY(int y) {
        this->y = y;
        return *this;
    }

private:
    int x;
    int y;
};

int main() {
    MyClass obj;
    obj.setX(1).setY(2);
    return 0;
}
