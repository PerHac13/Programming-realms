
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>


std::mutex mtx1,mtx2;

/*
    try_lock(m1,m2,..,mn) - non-blocking
 */

/*
*/


int X=0,Y=0;

void doSomeWorkForSeconds(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int& XorY,std::mutex& m,const char* desc) {
    for(int i = 0; i < 5; i++) {
        m.lock();
        XorY++;
        std::cout << desc << XorY << std::endl;
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY() {
    int useCount = 5;
    int XplusY = 0;
    while(1) {
        int lockResult = std::try_lock(mtx1,mtx2);
        if(lockResult == -1) {
            if(X != 0 && Y != 0) {
                useCount--;
                XplusY += X + Y;
                X = 0;
                Y = 0;
                std::cout << "XplusY: " << XplusY << std::endl;
            }
            mtx1.unlock();
            mtx2.unlock();
            if(useCount == 0) {
                break;
            }
        }
    }
}

int main() {
    std::thread t1(incrementXY,std::ref(X),std::ref(mtx1),"X: ");
    std::thread t2(incrementXY,std::ref(Y),std::ref(mtx2),"Y: ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}

// There are so many try_lock function
// 1. std::try_lock
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutex::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 8. std::shared_timed_mutex::try_lock
// 9. std::recursive_timed_mutex::try_lock
