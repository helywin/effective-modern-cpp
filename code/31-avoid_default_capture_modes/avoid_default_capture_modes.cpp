//
// Created by helywin on 2020/8/5.
//

#include <vector>
#include <functional>

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

void addDivisorFilter()
{
    auto divisor = 1 + 3;
    filters.emplace_back([&](int val) { return val % divisor; });
}

class Test
{
public:
    void addFilter1() const;
    void addFilter2() const;
    void addFilter3() const;
    int divisor;
};

void Test::addFilter1() const
{
    filters.emplace_back([this](int val) {
        int v = val % divisor;
        printf("addFilter1 %d\n", divisor);
        return v;
    });
}

void Test::addFilter2() const
{
    filters.emplace_back([=](int val) {
        int v = val % divisor;
        printf("addFilter2 %d\n", divisor);
        return v;
    });
}

void Test::addFilter3() const
{
    filters.emplace_back([divisor = divisor](int val) {
        int v = val % divisor;
        printf("addFilter3  %d\n", divisor);
        return v;
    });
}

int main()
{
    Test test;
    test.divisor = 2;
    test.addFilter1();
    test.addFilter2();
    test.addFilter3();
    test.divisor = 3;
    filters[0](6);
    filters[1](6);
    filters[2](6);
}