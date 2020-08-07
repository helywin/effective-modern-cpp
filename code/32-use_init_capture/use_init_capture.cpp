//
// Created by helywin on 2020/8/6.
//

#include <utility>
#include <memory>
#include <functional>

class Test {

};



int main()
{
    auto func = [v = std::make_unique<Test>()]{};
    auto func1 = std::bind([](const std::unique_ptr<Test> v) {}, std::make_unique<Test>());
    std::plus<> a;
    int b = a(1,2); // b = 1 + 2;
}