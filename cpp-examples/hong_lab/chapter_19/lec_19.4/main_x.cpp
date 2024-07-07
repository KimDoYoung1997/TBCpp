#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int resource1 = 0;
int resource2 = 0;
std::mutex mtx;

void thread_func1() {
    for (int i = 0; i < 1000; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        resource1++;
        resource2++;
    }
}

void thread_func2() {
    for (int i = 0; i < 1000; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        resource2++;
        resource1++;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1(thread_func1);
    std::thread t2(thread_func2);

    t1.join();
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "resource1: " << resource1 << std::endl;
    std::cout << "resource2: " << resource2 << std::endl;
    std::cout << "Time taken with single mutex: " << duration.count() << " seconds" << std::endl;

    return 0;
}
