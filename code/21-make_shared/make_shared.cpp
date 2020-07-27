//
// Created by bekl on 2020/7/20.
//

#include <memory>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point() = default;

    ~Point()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    auto u1{std::make_unique<Point>()};
    std::unique_ptr<Point> u2(new Point);
    auto s1{std::make_shared<Point>()};
    std::shared_ptr<Point> s2(new Point);
}