//
// Created by naipe on 2023/3/30.
//
#include <iostream>

#include "string"

class Entity {
private:
    std::string name;

public:
    Entity() : name("Unknown") {}
    Entity(const std::string &name) : name(name) {}

    const std::string &GetName() const {
        return name;
    }
};

int main() {
    Entity entity("Naipeng");


    std::cout << entity.GetName() << std::endl;
    return 0;
}