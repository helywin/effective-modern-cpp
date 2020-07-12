//
// Created by helywin on 2020/7/12.
//

#include <iostream>
#include <boost/type_index.hpp>
#include <iomanip>

using namespace std;
using boost::typeindex::type_id_with_cvr;

#define STR1(R)  #R
#define STR2(R)  STR1(R)

#define TYPE_OF(x) \
cout.setf(ios::left); \
cout.fill(' '); \
cout << setw(15) << STR2(x)" = " + type_id_with_cvr<decltype(x)>().pretty_name() << endl;

void someFunc(int, double)
{}

void auto_deducing()
{
    auto x = 27;
    TYPE_OF(x)
    const auto cx = x;
    TYPE_OF(cx)
    const auto &crx = x;
    TYPE_OF(crx)
    const char a[] = "123456";
    TYPE_OF(a)
    TYPE_OF(&a)

    auto &&uref1 = x;
    TYPE_OF(uref1)
    auto &&uref2 = cx;
    TYPE_OF(uref2)
    auto &&uref3 = crx;
    TYPE_OF(uref3)
    auto &&uref4 = 0;
    TYPE_OF(uref4)
    auto func1 = someFunc;
    TYPE_OF(func1)
    auto &func2 = someFunc;
    TYPE_OF(func2)
    auto a1 = a;
    TYPE_OF(a1)
    auto &a2 = a;
    TYPE_OF(a2)
    auto &&a3 = a;
    TYPE_OF(a3)

    auto x1 = 0;
    TYPE_OF(x1)
    auto x2(27);
    TYPE_OF(x2)
    auto x3 = {27};
    TYPE_OF(x3)
    auto x4{27};
    TYPE_OF(x4)
}

int main()
{
    auto_deducing();
}