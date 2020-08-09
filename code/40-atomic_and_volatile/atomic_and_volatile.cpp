//
// Created by helywin on 2020/8/9.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <atomic>

using namespace std::literals;

volatile int vi(0);

void func()
{
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(0.99ms);
        vi++;
        int a = vi;
        std::cout << "a" << a << " ";
        std::cout.flush();
    }
}

int main()
{
    auto fut = std::async(std::launch::async, func);
    vi = 10;
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(1ms);
        vi++;
        int a = vi;
        std::cout << "b" << a << " ";
        std::cout.flush();
    }
    fut.get();

    std::atomic<int> x;
    std::atomic<int> y(x.load(std::memory_order::memory_order_consume));
    y.store(x.load());
}