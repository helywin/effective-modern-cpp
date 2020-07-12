//
// Created by helywin on 2020/7/12.
//

#include <iostream>
#include <boost/type_index.hpp>
#include <iomanip>

using namespace std;
using boost::typeindex::type_id_with_cvr;

#define FUNC_BODY \
cout.setf(ios::left); \
cout.fill(' '); \
cout << setw(25) << "T = " + type_id_with_cvr<T>().pretty_name(); \
cout << setw(25) << "param = " + type_id_with_cvr<decltype(param)>().pretty_name() << endl;

#define IN_TYPE(type) \
cout.setf(ios::left); \
cout.fill(' '); \
cout << setw(25) << "IN = " + type_id_with_cvr<decltype(type)>().pretty_name();

template<typename T>
void func(T param)
{
    FUNC_BODY
}

template<typename T>
void func_ref(T &param)
{
    FUNC_BODY
}

template<typename T>
void func_const_ref(const T &param)
{
    FUNC_BODY
}

template<typename T>
void func_pointer(T *param)
{
    FUNC_BODY
}

template<typename T>
void func_universal_ref(T &&param)
{
    FUNC_BODY
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

void deducing_template()
{
    int x = 0;
    const int c_x = x;
    const int &cr_x = x;
    const int *cp_x = &x;
    const int *const cpc_x = &x;
    const char *const cpc_s = "123456";
    const char cp_s[] = "123456";
    cout << "----void func_ref(T &param)----" << endl;
    IN_TYPE(x)
    func_ref(x);
    IN_TYPE(c_x)
    func_ref(c_x);
    IN_TYPE(cr_x)
    func_ref(cr_x);

    cout << "----void func_const_ref(const T &param)----" << endl;
    IN_TYPE(x)
    func_const_ref(x);
    IN_TYPE(c_x)
    func_const_ref(c_x);
    IN_TYPE(cr_x)
    func_const_ref(cr_x);

    cout << "----void func_pointer(T *param)----" << endl;
    IN_TYPE(x)
    func_pointer(&x);
    IN_TYPE(cp_x)
    func_pointer(cp_x);
    IN_TYPE(cpc_x)
    func_pointer(cpc_x);
    IN_TYPE(cpc_s)
    func_pointer(cpc_s);
    IN_TYPE(cp_s)
    func_pointer(cp_s);

    cout << "----void func_universal_ref(T &&param)----" << endl;
    IN_TYPE(x)
    func_universal_ref(x);
    IN_TYPE(c_x)
    func_universal_ref(c_x);
    IN_TYPE(cr_x)
    func_universal_ref(cr_x);
    IN_TYPE(0)
    func_universal_ref(0);

    cout << "----void func(T param)----" << endl;
    IN_TYPE(x)
    func(x);
    IN_TYPE(c_x)
    func(c_x);
    IN_TYPE(cr_x)
    func(cr_x);
    IN_TYPE(0)
    func(0);
    IN_TYPE(cp_x)
    func(cp_x);
    IN_TYPE(cpc_x)
    func(cpc_x);
    IN_TYPE(cpc_s)
    func(cpc_s);
    IN_TYPE(cp_s)
    func(cp_s);

    cout << "array size: " << arraySize(cp_s) << endl;
}

int main()
{
    deducing_template();
}