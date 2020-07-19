//
// Created by helywin on 2020/7/19.
//

#include <memory>
#include <iostream>
#include <vector>

class Point;

class Shared;

std::vector<std::shared_ptr<Point>> points;
std::vector<std::shared_ptr<Shared>> shareds;

class Point
{
public:
    int x;
    int y;

    static void deleter(Point *p)
    {
        std::cout << "x:" << p->x << " y:" << p->y << std::endl;
        delete p;
    }

    void addShared()
    {
        points.emplace_back(this);
    }
};


class Shared : public std::enable_shared_from_this<Shared>
{
public:
    static void deleter(Shared *p)
    {
        std::cout << "delete shared" << std::endl;
        delete p;
    }

    void addShared()
    {
        shareds.emplace_back(shared_from_this());
    }

    ~Shared()
    {
        std::cout << "default deleter" << std::endl;
    }
};

int main()
{
    auto customDeleter1 = [](Point *p) {
        std::cout << "x1:" << p->x << " y1:" << p->y << std::endl;
        delete p;
    };

    auto customDeleter2 = [](Point *p) {
        std::cout << "x2:" << p->x << " y2:" << p->y << std::endl;
        delete p;
    };

    std::shared_ptr<Point> p{new Point, Point::deleter};
//    p->addShared(); // double free as it was not inherit `enable_shared_from_this`
    std::shared_ptr<Point> p1{new Point, customDeleter1};
    std::shared_ptr<Point> p2{new Point, customDeleter2};
    std::shared_ptr<Shared> p3{new Shared, Shared::deleter};    //without double free
    std::shared_ptr<Shared> p4{std::make_shared<Shared>()};    //without double free
    std::weak_ptr<Shared> pw{p4};
    p4 = nullptr;
    std::cout << "nullptr" << std::endl;
    auto ps = pw.lock();
    std::cout << "is nullptr:" << ps << std::endl;
    std::cout << pw.expired() << std::endl;
    p3->addShared();


}