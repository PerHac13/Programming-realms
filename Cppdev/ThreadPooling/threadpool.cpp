#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <sstream>
#include <mutex>
#include <condition_variable>

class ThreadPool {
    public:
        ThreadPool(size_t numThreads) : stop(false) {
            for (size_t i = 0; i < numThreads; ++i){
                workers.emplace_back([this] {
                    for(;;) {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        
                        auto task = std::move(tasks.front());
                        tasks.pop();
                        lock.unlock();
                        task();
                    }
                });
            }
        }

        template<class F>
        void enqueue(F&& task) {
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                tasks.emplace(std::forward<F>(task));
            }
            condition.notify_one();
        }

        ~ThreadPool() {
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                stop = true;
            }
            condition.notify_all();
            for (std::thread &worker : workers)
                worker.join();
        }

    private:
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::mutex queueMutex;
        std::condition_variable condition;
        bool stop;
};

std::string get_thread_id() {
    auto id = std::this_thread::get_id();
    std::stringstream ss;
    ss << id;
    return ss.str();
}

int main() {

    ThreadPool pool(4); // pool of n threads

    std::cout << "Thread Pool Created\n";
    std::cout << "Enqueue (Assign) some tasks\n";

    for (int i = 0; i < 23; i++) {
        pool.enqueue([i] {
            printf("Task %d is running on thread %s\n", i, get_thread_id().c_str());
            std::this_thread::sleep_for(std::chrono::seconds(1));

        });
    } 

    // Main thread sleeps for 10 seconds can be used for other tasks
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;


}