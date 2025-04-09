#include <iostream>
#include <thread>
#include <chrono>  
using namespace std;
using namespace std::chrono;

int main()
{
    
    auto startTime = high_resolution_clock::now();


    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Sec: " << duration.count() / 1000000.0 << "\n";

    return 0;
}