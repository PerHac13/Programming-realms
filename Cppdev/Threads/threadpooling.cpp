#include<bits/stdc++.h>

using namespace std;


class ThreadPool {
    public:
        ThreadPool(size_t num_threads) : stop(false) {
            for(size_t i = 0; i < num_threads; i++) {
                workers.emplace_back([this] {
                    for(;;) {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if(stop && tasks.empty()) {
                            return;
                        }
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
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(std::forward<F>(task));
            lock.unlock();
            condition.notify_one();
        }

      ~ThreadPool() {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
        lock.unlock();
        condition.notify_all();
        for (std::thread &worker : workers) {
            worker.join();
        }
      }
    private:
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::mutex queue_mutex;
        std::condition_variable condition;
        bool stop;
};



std::string get_thread_id() {
    auto myid = std::this_thread::get_id();
    std::stringstream ss;
    ss << myid;
    return ss.str();
}


int main() {
    ThreadPool pool(4);

    std::cout<< "Thread Pool Created\n";
    std::cout<< "Enqueue (Assign) some tasks \n";

    for(int i = 0; i < 8; i++) {
        pool.enqueue([i] {
            printf("Hello from thread %d: %s\n", i,get_thread_id().c_str());
            std::this_thread::sleep_for(std::chrono::seconds(1));
        });
    }

    // Main thread continues doing other things
    // while the other threads are working
}