//
// Created by bekl on 2020/7/27.
//
#include <boost/type_index.hpp>
#include <iostream>


using boost::typeindex::type_id_with_cvr;

void func(int &&v)
{

}

int main()
{
    int &&a = 1;
    std::cout << &a << std::endl;
    func(std::forward<int>(a));
    int b[2];
    b[1] = std::move(a);
    std::cout << &b[1] << std::endl;
    a = 2;
    std::cout << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
}