// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int balance = 0;
std::mutex m;
std::condition_variable cv;

void addMoney(int money) {
    std::lock_guard<std::mutex> lg(m);
    balance += money;
    cout << "Amount added Curr Balance: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []{return balance != 0;});
    if(balance >= money) {
        balance -= money;
        cout << "Amount Withdrawn Curr Balance: " << balance << endl;
    } else {
        cout << "Not Enough Money\n";
    }

    cout<< "Curr Balance: " << balance << endl;
}

int main() {
    std::thread t(withdrawMoney,200);
	std::thread t1(addMoney,500);
    std::thread t2(withdrawMoney, 700);
	std::thread t3(addMoney,400);

    t.join();
	t1.join();
	t2.join();
    t3.join();

	// cout << myAmount << endl;
	return 0;
}


// #include <iostream>
// #include <thread>
// #include <mutex>
// using namespace std;

// int myAmount = 0;
// std::mutex m;

// void addMoney() {
// 	std::lock_gaurd<std::mutex> lock(m);
// 	++myAmount;
// }

// int main() {
// 	std::thread t1(addMoney);
// 	std::thread t2(addMoney);

// 	t1.join();
// 	t2.join();

// 	cout << myAmount << endl;
// 	return 0;
// }