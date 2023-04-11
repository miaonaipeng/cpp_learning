//
// Created by 缪乃鹏 on 4/10/23.
//
#include <functional>
#include <iostream>
#include <vector>

int main() {
    // 定义一个lambda表达式multiply，接受两个整数x，y，返回它们的乘积。
    auto multiply = [](int x, int y) { return x * y; };
    std::cout << multiply(3, 5) << std::endl;
    // 2. 定义一个 lambda 表达式 `apply_operation`
    auto apply_operation = [](int n, const std::vector<int> &numbers, const std::function<int(int, int)> &operation) {
        std::vector<int> result;
        for (int num: numbers) {
            result.push_back(operation(num, n));
        }
        return result;
    };
    std::vector<int> numbers{1, 2, 3, 4, 5};
    int factor = 3;

    std::vector<int> result = apply_operation(factor, numbers, multiply);
    for (int num: result) {
        std::cout << num << " ";
    }
    return 0;
}