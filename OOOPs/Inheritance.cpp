#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

#define pb puch_back

using namespace std;

class A{
    public:
    void Afunc(){
        cout<<"Single Inheritence"<<endl;

    }
};
//single inheritance  can be changed into multiple inheritance by as class B : public A,public C;
class B : public A{};

class C: public A{
    public:
    void Cfunc(){
        cout<<"Function C"<<endl;
    }
};
// Multi Level Inheritance
class D : public C{};

//multi level + multiple inheritance == hybrid inheritance

//Hierarchical Inheritance is explained by it name itself


int main(){

    B b;
    b.Afunc();


    return 0;
}