//
// Created by helywin on 2020/7/12.
//

#include <mutex>

class Polynomial
{
public:
    void caculate() const
    {
        std::lock_guard<std::mutex> guard(m);
        valid = !valid;
    }

private:
    mutable std::mutex m;
    mutable bool valid{false};
};

int main()
{
    Polynomial p;
    auto a = p;
}