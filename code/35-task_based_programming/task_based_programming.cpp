//
// Created by helywin on 2020/8/7.
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

int main()
{
    auto future = std::async([start = 0] { printFunc(1, 6, 1s); });
    std::this_thread::sleep_for(0.5s);
    printFunc(7, 2, 0.3s);
    future.get();
}
