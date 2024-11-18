#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>


// join(), detach(), joinable() at bottom

void threadFunction()
{
    // simulate work 1
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in thread\n";

    // simulate work 2
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 2 in thread\n";
}

// int main()
// {
//     // create thread
//     std::thread t(threadFunction);

//     std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work

//     std::cout << "Finished work 1 in main\n";

//     std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work

//     std::cout << "Finished work 2 in main\n";

//     t.join();

//     // thread using lambda function
//     std::thread t2([](){
//         std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
//         std::cout << "Finished work in thread\n";
//     });

//     std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work

//     std::cout << "Finished work in main\n";

//     t2.join();



//     return 0;
// }


// using functor
// class Base {
//     public:
//         void operator()(int x) {
//             std::cout << "Base class functor\n";
//             while(x--){
//                 std::cout << x << std::endl;
//             }
//         }
        
// };

// int main() {
//     Base base;
//     std::thread t(base, 3);
//     t.join();
//     std:: thread t2((Base()), 3);
//     t2.join();
//     return 0;
// }

// using non-static member function
// class Base {
//     public: 
//         void run(int x) {
//             std::cout << "Base class functor\n";
//             while(x--){
//                 std::cout << x << std::endl;
//             }
//         }
// };

// int main() {
//     Base base;
//     std::thread t(&Base::run, &base, 3);
//     t.join();
//     return 0;
// }


// using static member function

class Base {
    public: 
        static void run(int x) {
            std::cout << "Base class functor\n";
            while(x--){
                std::cout << x << std::endl;
            }
        }
};

int main() {
    Base base;
    std::thread t(&Base::run, 3);
    t.join();
    return 0;
}



/*
join():
    blocks the current thread until the thread identified by *this finishes its execution.

detach():
    separates the thread of execution from the thread object, allowing execution to continue independently.

joinable():
    returns whether the thread object identifies an active thread of execution.

note:
    if you call join() and detach() on the same thread object, the program will terminate.
    if you call join() or detach() on a thread object that has already been joined or detached, the program will terminate. give an system error on runtime not complile time.

*/