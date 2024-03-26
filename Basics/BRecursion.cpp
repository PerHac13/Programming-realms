#include<iostream>

using namespace std;


int Fibonacci(int n){

    if(n==0 || n==1)        //base condition
        return n;

    return Fibonacci(n-1)+Fibonacci(n-2);
}

int factorial(int n){

    if(n==0)        //base condition
    return 1;

    int pf=factorial(n-1);
    return n*pf;
}

int pow(int n,int p){

    if(p==0)        //base condition
        return 1;

    // int pp=pow(n,p-1);
    return pow(n,p-1)*n;
}

int sumtill(int n){

    if(n==0)        //base condition
        return 0;

    int psum=sumtill(n-1);
    return n+psum;
}


int main(){

    int n;

    cin>>n;

    cout<<sumtill(n)<<endl;

    int a,p;

    cin>>a>>p;

    cout<<pow(a,p)<<endl;

    int f;
    cin>>f;

    cout<<factorial(f)<<endl;

    int fn;
    cin>>fn;

    cout<<Fibonacci(fn)<<endl;


    return 0;
}