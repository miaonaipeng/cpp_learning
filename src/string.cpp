//
// Created by naipe on 2023/3/28.
//
// 使用字符数组
#include <cstring>// 包含字符串函数
#include <iostream>
using namespace std;

long double operator"" _kg(long double x) { return x * 1000; }
long double operator"" _g(long double x) { return x; }
long double operator"" _mg(long double x) { return x / 1000; }


int main() {
    long double weight = 3.6_kg;// weight is 3600 grams
    cout << "Weight: " << weight << endl;

    return 0;
}