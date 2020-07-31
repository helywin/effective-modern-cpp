//
// Created by helywin on 2020/7/31.
//

// 1 abandon overloading
// 2 pass by const T&
// 3 pass by value
// 4 use tag dispatch


#include <string>

#include <set>
#include <string>
#include <chrono>
#include <iostream>

std::multiset<std::string> names;

std::string findNameAt(int index)
{ return std::string("Index: ") + std::to_string(index); }


template<typename T>
void AddNamesImpl(T &&v, std::true_type)
{
    auto now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count() << " add name: " << findNameAt(v) << std::endl;
    names.emplace(findNameAt(v));
}

template<typename T>
void AddNamesImpl(T &&v, std::false_type)
{
    auto now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count() << " add name: " << v << std::endl;
    names.emplace(v);
}

template<typename T>
void addNames(T &&v)
{
    AddNamesImpl(v, std::is_integral<typename std::remove_reference<T>::type>());
}

class Person
{
public:
    template<typename T, typename = typename std::enable_if<!std::is_base_of<Person, typename std::decay<T>::type>::value>::type>
    Person(T &&other)
    {

    }
};

class Person1
{
public:
    template<
            typename T,
            typename = typename std::enable_if<
                    !std::is_same<Person,
                            typename std::decay<T>::type
                    >::value
            >::type
    >
    explicit Person1(T &&n)
    {}
};

int main()
{
    auto s = u"21";
    std::string str{"Darla"};
    addNames(str);
    addNames(std::string{"Jane"});
    addNames("Dog");
    addNames(1);
    short b = 2;
    addNames(b);
    Person person(1);
    Person p1(person);
}