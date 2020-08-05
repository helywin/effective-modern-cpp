//
// Created by helywin on 2020/8/5.
//

#include <cstddef>
#include <cstdint>
#include <utility>

void f1(std::size_t size)
{

}

void f2(int pf(int))
{
    pf(1);
}

int proc(int a)
{
    return a;
}

int proc(int a, int b)
{
    return a + b;
}

template<typename T>
void fwd(T &&t)
{
    f1(std::forward<T>(t));
//    f2(std::forward<T>(t));
}

class Test
{
public:
    static const std::size_t val = 20;
};

struct IPv4Header
{
    std::uint32_t version: 4,
            IHL: 4,
            DSCP: 6,
            ECN: 2,
            totalLength: 16;
};

int main()
{
    IPv4Header header{};
    fwd(header.version);
}