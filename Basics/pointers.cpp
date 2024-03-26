#include<iostream>

using namespace std;

int PtFaP(int *b){

    *b=*b/2;


    return 0;
}

int PtFaI(int b){

    b++;

    return 0;
}

int PtP(){

    int a=10;
    int *p=&a;

    cout<<*p<<endl;

    int **q=&p;
    cout<<q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;


    return 0;
}

int PnA(){

int arr[]={10,11,12,22,34,45,56,67,78,89,90};
    cout<<*arr<<endl;

    int *ptr=arr;

    for(int i=0;i<11;i++){
        cout<<*ptr<<endl;
        ptr++;
    }

    return 0;
}




int basic(){

    int a=10;
    int *aptr=&a;

    cout<<*aptr<<endl;
    *aptr=a+10;
    cout<<a<<endl;
    cout<<aptr<<endl;

    return 0;
}

int main(){


    basic();
    cout<<endl;

    PtP();
    cout<<endl;

    int b=26;
    
    PtFaI(b);
    cout<<"The value of b= "<<b<<endl;

    int *bptr=&b;                //not required
    PtFaP(bptr);                 // ptFap(&b);
    cout<<"Passing Pointer to function then b= "<<b<<endl;
    cout<<endl;

    PnA(); 
    cout<<endl;
    //! no program rum after it



    return 0;
}