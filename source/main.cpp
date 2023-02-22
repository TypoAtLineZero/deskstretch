#include <chrono>
#include <iostream>
#include <thread>

void fa(int& x){
    for(int i=0; i<4; ++i){
        ++x;
        std::cout << "Thread A: " << x << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

void fb(int& x){
    for(int i=0; i<4; ++i){
        ++x;
        std::cout << "Thread B: " << x << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}

int main() {

    // TODO
    // - Setup CMake
    // - DOD
    // - Qt

    int x = {1000};
    std::thread ta(fa, std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::thread tb(fb, std::ref(x));

    for(int i=0; i<4; ++i){
        ++x;
        std::cout << "Thread M: " << x << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    ta.join();
    tb.join();
}