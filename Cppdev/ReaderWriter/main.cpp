#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <queue>
#include <condition_variable>

std::mutex consoleMutex;


void printTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << std::put_time(std::localtime(&now_c), "[%H:%M:%S] ");
}

class PizzaCounter {
private:
    struct Request {
        bool isReader;
        int id;
        std::condition_variable* cv;
        bool* done;
        
        Request(bool isRead, int identifier) 
            : isReader(isRead), id(identifier), cv(new std::condition_variable()), done(new bool(false)) {}
    };

    std::mutex mtx;
    std::queue<Request> requestQueue;
    int activeReaders{0};
    bool activeWriter{false};
    std::atomic<int> currentOrder{0};
    int nextId{0};

    bool canProcessNext(const Request& req) {
        if (req.isReader) {
            // Readers can proceed if no writer is active and no earlier writer is waiting
            if (!activeWriter) {
                bool earlierWriter = false;
                auto tempQueue = requestQueue;
                while (!tempQueue.empty() && tempQueue.front().id < req.id) {
                    if (!tempQueue.front().isReader) {
                        earlierWriter = true;
                        break;
                    }
                    tempQueue.pop();
                }
                return !earlierWriter;
            }
        } else {
            // Writers can proceed if no readers/writers are active
            return !activeWriter && activeReaders == 0;
        }
        return false;
    }

public:
    void startRead() {
        std::unique_lock<std::mutex> lock(mtx);
        int myId = nextId++;
        Request myRequest(true, myId);
        requestQueue.push(myRequest);

        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            printTimestamp();
            std::cout << "Reader #" << myId << " queued" << std::endl;
        }

        while (!canProcessNext(myRequest)) {
            myRequest.cv->wait(lock);
        }

        activeReaders++;
        requestQueue.pop();
        delete myRequest.cv;
        delete myRequest.done;

        // Wake up other potential readers
        checkQueue();
    }

    void endRead() {
        std::unique_lock<std::mutex> lock(mtx);
        activeReaders--;
        checkQueue();
    }

    void startWrite() {
        std::unique_lock<std::mutex> lock(mtx);
        int myId = nextId++;
        Request myRequest(false, myId);
        requestQueue.push(myRequest);

        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            printTimestamp();
            std::cout << "Writer #" << myId << " queued" << std::endl;
        }

        while (!canProcessNext(myRequest)) {
            myRequest.cv->wait(lock);
        }

        activeWriter = true;
        requestQueue.pop();
        delete myRequest.cv;
        delete myRequest.done;
    }

    void endWrite() {
        std::unique_lock<std::mutex> lock(mtx);
        activeWriter = false;
        currentOrder++;
        checkQueue();
    }

    void checkQueue() {
        if (!requestQueue.empty()) {
            Request& next = requestQueue.front();
            if (canProcessNext(next)) {
                next.cv->notify_one();
            }
        }
    }

    int getCurrentOrder() const {
        return currentOrder;
    }
};


void reader(PizzaCounter& counter, int orderToCheck) {
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Reader requesting to check order " << orderToCheck << std::endl;
    }

    counter.startRead();
    
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Reader started checking order " << orderToCheck << std::endl;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(10));  // Reading takes 10 seconds
    
    bool isReady = orderToCheck <= counter.getCurrentOrder();
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Reader: Order " << orderToCheck 
                  << (isReady ? " is prepared" : " is not prepared yet") << std::endl;
    }
    
    counter.endRead();
}

void writer(PizzaCounter& counter) {
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Writer requesting to prepare next order" << std::endl;
    }

    counter.startWrite();
    
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Writer: Order " << (counter.getCurrentOrder() + 1) << " is preparing" << std::endl;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(15));  // Writing takes 15 seconds
    
    counter.endWrite();
    
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        printTimestamp();
        std::cout << "Writer: Order " << counter.getCurrentOrder() << " is prepared" << std::endl;
    }
}

int main() {
    PizzaCounter counter;
    std::vector<std::thread> threads;
    std::string command;
    
    std::cout << "Enter commands (R <order_number> or W):\n";
    while (std::getline(std::cin, command)) {
        try {
            if (command[0] == 'R') {
                int orderNum;
                if (sscanf(command.c_str(), "R %d", &orderNum) == 1) {
                    std::thread readerThread(reader, std::ref(counter), orderNum);
                    readerThread.detach();
                } else {
                    std::cout << "Invalid command. Use 'R <order_number>'\n";
                }
            }
            else if (command[0] == 'W') {
                std::thread writerThread(writer, std::ref(counter));
                writerThread.detach();
            }
            else if (command == "quit") {
                break;
            }
            else {
                std::cout << "Invalid command. Use 'R <order_number>' or 'W'\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}