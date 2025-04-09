#include <iostream>
#include <thread>
#include <chrono>  
using namespace std;
using namespace std::chrono;

void fun(int x)
{
    while (x-- > 0)
    {
        cout << x << "\n";
    }
}

int main()
{
    auto startTime = high_resolution_clock::now();

    // std::thread t1(fun, 11);
    // t1.join();
    fun(11);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Sec: " << duration.count() / 1000000.0 << "\n";

    return 0;
}