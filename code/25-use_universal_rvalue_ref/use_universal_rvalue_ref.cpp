//
// Created by bekl on 2020/7/28.
//

#include <string>
#include <iostream>
#include <type_traits>

class Test1
{
public:
    template<typename T>
    void setName(T &&newName)
    {
        name = std::move(newName);
    }

    template<typename T>
    void setInfo(T &&newInfo)
    {
        info = std::forward<T>(newInfo);
    }

private:
    std::string name;
    std::string info;
};

template<typename T>
T funcPrint(const T &t)
{
    printf("[%d]", t);
    return t;
}

template<typename ...T>
void unwrapper(T ...args)
{}

// 递归解包和直接用c++17解包规则

template<typename T, typename ...Args>
void funcPrint(const T &t, Args ...arg)
{
    printf("(%d)", t);
    unwrapper(funcPrint(arg)...);
}

template<typename T>
T unpacker(const T &t)
{
    std::cout << ',' << t;
    return t;
}

template<typename T, typename ...Args>
void write_line(const T &t, const Args &...data)
{
    unwrapper(unpacker(data)...);
}


template<typename ...Args>
void printer(Args &&... args)
{
    (std::cout << ... << args) << '\n';
}

class TestRVO
{
public:
    TestRVO()
    {
        std::cout << "constructor" << std::endl;
    }
    TestRVO(const TestRVO &other) = default;
    TestRVO &operator=(const TestRVO &rhs) = default;
};

//return value optimize
TestRVO testRvoFunc() {
    TestRVO rvo;
    return std::move(rvo);
}

int main()
{
    Test1 test1;
    std::string name = "hello";
    std::cout << name << std::endl;
    test1.setName(name);
    std::cout << name.length() << std::endl;

    std::string info = "info";
    std::cout << info << std::endl;
    test1.setInfo(info);
    std::cout << info.length() << std::endl;

    funcPrint(1, 2, 3);
    printer(1, 2, 3);
    auto a = testRvoFunc();
}