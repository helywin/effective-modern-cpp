//
// Created by helywin on 2020/8/8.
//

#include <thread>

// thread_local

thread_local int g_n = 1;

void f1()
{
    g_n++;
    printf("f1 thread_id=%d, n=%d\n", std::this_thread::get_id(),g_n);
}

void foo()
{
    thread_local int i=0;
    printf("foo thread_id=%d, i=%d\n", std::this_thread::get_id(), i);
    i++;
}

void f2()
{
    foo();
    foo();
}

int main() {
    g_n++;
    f1();
    std::thread t1(f1);
    std::thread t2(f1);

    t1.join();
    t2.join();


    f2();
    std::thread t4(f2);
    std::thread t5(f2);

    t4.join();
    t5.join();
    return 0;
}