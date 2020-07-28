//
// Created by bekl on 2020/7/27.
//

#include <type_traits>
#include <algorithm>
#include <chrono>
#include <iostream>

template<typename T>
decltype(auto) move(T &&param)
{
    using type = std::remove_reference<T> &&;
    return static_cast<T>(param);
}

class Test1
{
public:
    Test1(const int &lval)
    {
        std::cout << "Test(const int &lval)" << std::endl;
    }

    Test1(int &&rval)
    {
        std::cout << "Test(int &&rval)" << std::endl;
    }
};

template<typename T>
Test1 factory1(T &&param)
{
    return Test1(std::forward<T>(param));
}

template<typename T>
Test1 factory2(T &&param)
{
    return Test1(std::move(param));
}

int main()
{
    int a = 0;
    auto c = move(a);
    a = 2;
    auto b = std::move(a);
    a = 3;
    std::cout << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
    using std::chrono_literals::operator ""h;
    constexpr auto day = 24h;
    std::cout << day.count() << std::endl;
    factory1(a);
    factory1(1);
    factory2(a);
    factory2(1);
}