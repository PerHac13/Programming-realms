#include<iostream>
#include<memory>
using namespace std;

class MyClass {
    public:
        MyClass() {
            cout<<"Constructor"<<endl;
        }

        ~MyClass() {
            cout<<"Destructor"<<endl;
        }

        void myMethod() {
            cout<<"Method"<<endl;
        }
};


int main(){

{
    unique_ptr<int> uptr1(new int(5));
    unique_ptr<int> uptr2 = make_unique<int>(10);
    unique_ptr<int> uptr3;
    uptr3 = move(uptr1);
    cout<<*uptr3<<endl;
}

    shared_ptr<MyClass> sptr1(new MyClass());
    {
    shared_ptr<MyClass> sptr2 = make_shared<MyClass>();
    cout<<sptr2.use_count()<<endl;
    }
    cout<<sptr1.use_count()<<endl;
    {
        shared_ptr<MyClass> sptr3 = sptr1;
    cout<<sptr1.use_count()<<endl;
    }
    cout<<sptr1.use_count()<<endl;

    weak_ptr<MyClass> wptr;
    {
        wptr = sptr1;
        cout<<sptr1.use_count()<<endl;
    }
    cout<<sptr1.use_count()<<endl;

}