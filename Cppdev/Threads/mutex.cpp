#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>

std::mutex mtx;

int myAmount = 0;

void addMoney(int money) {
    mtx.lock();
    myAmount += money;
    std::cout << "Amount: " << myAmount << std::endl;
    mtx.unlock();
}

// try_lock() - non-blocking
// try_lock_for() - blocking for a duration

// example
int counter = 0;
void increasetheCounter(int x) {
    for(int i = 0; i < x; i++) {
        if(mtx.try_lock()) {
            // std::cout << "Counter: " << i << std::endl;
            counter++;
            mtx.unlock();
        } 
        // else {
        //     std::cout << "Counter is locked\n";
        // }
    }
}

 

int main() {
    
    std::thread t1(increasetheCounter, 1000000);
    std::thread t2(increasetheCounter, 2000000);

    t1.join();
    t2.join();
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}


void printEven(int x) {
    for(int i = 0; i < x; i++) {
        if(i % 2 == 0) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Even: " << i << std::endl;
        }
    }
}

void printOdd(int x) {
    for(int i = 0; i < x; i++) {
        if(i % 2 != 0) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Odd: " << i << std::endl;
        }
    }
}