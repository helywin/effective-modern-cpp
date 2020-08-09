//
// Created by helywin on 2020/8/8.
//
#include <future>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals;

std::mutex printMutex;

template<typename T>
void printFunc(int start, int interval, T sec)
{
    for (int i = start; i < start + interval; ++i) {
        printMutex.lock();
        std::cout << std::this_thread::get_id() << ": " << i << "  time: " <<
                  std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
        printMutex.unlock();
        std::this_thread::sleep_for(sec);
    }
}

void f()
{
    std::this_thread::sleep_for(1s);
}

template<typename F, typename ...Ts>
inline auto reallyAsyc(F &&f, Ts &&...ts)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Ts>(ts)...);
}

int main()
{
    auto future = std::async(std::launch::deferred, [start = 0] { printFunc(1, 6, 1s); });
//    auto future1 = std::async(std::launch::async, );
    auto future1 = reallyAsyc([start = 0] { printFunc(10, 3, 0.5s); });
    std::this_thread::sleep_for(0.5s);
    printFunc(7, 2, 0.3s);
    future.get();
    future1.get();

    auto fut = std::async(std::launch::deferred, f);
    if (fut.wait_for(0s) == std::future_status::deferred) {
        std::cout << "deferred" << std::endl;
    } else {
        while (fut.wait_for(100ms) != std::future_status::ready) {
        }
    }

}
