#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

#define pb puch_back

using namespace std;

/*polymorphism 
    compile time 
        function overloading
        operator overloading
    runtime
        virtual function 
*/



//function overloading
class A{
    public:
    void fun(){
        cout<<"Function with no argument"<<endl;
    }
    void fun(int x){
        cout<<"Function with int argument"<<endl;
    }
    void fun(double x){
        cout<<"Function with double argument"<<endl;
    }
};

//operator oveloading
class Complex {
private:
    int real, imag;
 
public:
    Complex(){}                 //default constructor
    Complex(int r, int i){      //parametric constructor
        real = r;
        imag = i;
    }

    Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print()
    {
      cout << real << " + i" <<imag << endl;
    }
};

// virtual function
class base{
    public:
    virtual void print(){
        cout<<"this is the base class print function"<<endl;
    }
    void display(){
        cout<<"this is the base class display function"<<endl;
    }
};

class derived:public base{
    public:
    void print(){
        cout<<"this is the derived class print function"<<endl;
    }
    void display(){
        cout<<"this is the derived class display function"<<endl;
    }
};


int main(){

    A a;
    a.fun();
    a.fun(9);
    a.fun(5.4);

    Complex c1(12,7),c2(6,7),c3=c1+c2;
    c3.print();
    
    base *bptr;
    derived d;
    bptr=&d;

    bptr ->print();
    bptr ->display();

    return 0;
}