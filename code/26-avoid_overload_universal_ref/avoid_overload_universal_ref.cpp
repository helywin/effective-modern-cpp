//
// Created by helywin on 2020/7/30.
//

#include <set>
#include <string>
#include <chrono>
#include <iostream>

std::multiset<std::string> names;

template<typename T>
void addNames(T &&name)
{
    auto now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count() << " add name: " << name << std::endl;
    names.emplace(name);
}

std::string findNameAt(int index)
{ return "Index"; }

void AddNames(int index)
{
    auto now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count() << " add name: " << findNameAt(index) << std::endl;
    names.emplace(findNameAt(index));
}

class Test
{
public:
    template<typename T>
    explicit Test(T &&n) : name(std::forward<T>(n))
    {}

    explicit Test(int idx) : name(findNameAt(idx))
    {}

    Test(const Test &other) {
        name = other.name;
    }

    Test(Test &&other) {
        name = other.name;
    }



private:
    std::string name;
};

int main()
{
    std::string str{"Darla"};
    addNames(str);
    addNames(std::string{"Jane"});
    addNames("Dog");
//    addNames(1);
//    short b = 2;
//    addNames(b);

    Test t("name");
    Test t1(t);

}