// Type your code here, or load an example.
#include<iostream>

using namespace std;

void trial(int *a, int *b){
    *a=*a+1;
    *b=*b+1;
    cout<<*a<<' '<<' '<<*b<<endl;
}

void passBy(int a,int b){
    a++;
    b++;
    cout<<a<<' '<<b<<endl;
}

void func2(int arr[]){
    for(int i=0;i<10;++i){
        arr[i]=i;
    }
}

int * func3(int size){
    cout<<"size: "<<size<<endl;
    auto arr= new int[size];
    for(int i=0;i<size;++i){
        arr[i]=i;
    }

    return arr;
}

int main(){
   
   int arr[10];
   int a=3,b=4;
    cout<<a<<' '<<' '<<b<<endl;
    passBy(3,4);
    trial(&a,&b);
    func2(arr);


    for(int i=0;i<10;++i){
        cout<<arr[i]<<' ';
    }

    auto ptr = func3(3);

    // while(ptr!= nullptr){
    //     cout<<*ptr;
    //     ptr++;
    // }
    for(int i=0;i<3;++i){
        cout<<ptr[i]<<endl;
        // ptr++;
    }


    // cout<<a<<' '<<' '<<b<<endl;
    return 0;
}