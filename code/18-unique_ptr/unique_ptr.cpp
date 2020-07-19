//
// Created by helywin on 2020/7/19.
//

#include <memory>
#include <iostream>

class Point
{
public:
    int x;
    int y;

};

int main()
{
    auto deleter = [](Point *p) {
        std::cout << "delete Point" << std::endl;
        delete p;
    };
    std::unique_ptr<Point, decltype(deleter)> p{new Point, deleter};
}