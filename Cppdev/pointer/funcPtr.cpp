#include<iostream>

using namespace std;

int getNumber() {
    return 5;
}

// int add(int a, int b);
int add(int, int, int);


int main() {
    cout<<getNumber<<endl;

    int (*funcPtr)() = getNumber;
    cout<<funcPtr<<endl;

    int (*addPtr)(int, int,int) = add;

    // cout<<addPtr(5, 6)<<endl;
    cout<<addPtr<<endl;

    cout<<addPtr(5, 6,11)<<endl;
    cout<<addPtr<<endl;

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c=0) {
    return a + b + c;
}