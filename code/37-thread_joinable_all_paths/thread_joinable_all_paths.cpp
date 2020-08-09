//
// Created by helywin on 2020/8/8.
//


#include <thread>
#include <functional>
#include <vector>
#include <utility>

//单引号分隔数字
constexpr auto tenMillion = 10'000'000;

bool doWork(std::function<bool(int)> filter, int maxVal = tenMillion)
{
    std::vector<int> goodVals;
    std::thread t([&filter, maxVal, &goodVals] {
        for (auto i = 0; i <= maxVal; ++i) {
            if (filter(i)) goodVals.push_back(i);
        }
    });
    auto nh = t.native_handle();
    sched_param param;
    int pol = SCHED_FIFO;
    param.sched_priority = sched_get_priority_max(pol);
    pthread_setschedparam(nh, pol, &param);

    if (true) {
        t.join();
        return true;
    }
}

class ThreadRAII
{
public:
    enum class DtorAction
    {
        join, detach
    };

    ThreadRAII(std::thread &&t, DtorAction a) :
            action(a), t(std::move(t))
    {}

    ~ThreadRAII()
    {
        if (t.joinable()) {
            if (action == DtorAction::join) {
                t.join();
            } else {
                t.detach();
            }
        }
    }

    std::thread &get()
    { return t;  }

private:
    DtorAction action;
    std::thread t;
};

int main()
{

}