#include<iostream>

using namespace std;

int main(){

    //heap

    int a=10;                   //stored in stacks
    int *p=new int();           //allocate memory in heap

    cout<<p<<endl;

    *p=20;

    delete(p);                  //deallocate memory
                                //but only value get deleted and location remain as dangling pointer

    p=new int[4];                // reusing pointer for storing array
    delete[]p;                   //deleting the array but still dangling pointer remains.

    p=NULL;                      //to remove pointer along with dangling pointer 
                                 //to avoid Data leaks at all costs bcz it cause storage problem on servers

    return 0;
}