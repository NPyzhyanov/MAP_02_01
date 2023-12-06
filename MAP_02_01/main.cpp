#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

std::atomic<int> clients_counter;
std::chrono::time_point<std::chrono::steady_clock> start;
std::mutex ostream_mut;

#include "requesting_function.h"
#include "responding_function.h"

int main()
{
    clients_counter = 0;
    start = std::chrono::steady_clock::now();
    std::cout << "0ms\tStart of service." << std::endl;
    
    std::thread clients_thread(requesting_function);
    std::thread manager_thread(responding_function);
    
    clients_thread.join();
    manager_thread.join();
    
    auto finish = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << diff.count() << "ms\tAll clients are served." << std::endl;
    
    return 0;
}
