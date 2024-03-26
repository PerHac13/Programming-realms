#include<iostream>

using namespace std;


void inc(int n){
    if(n==0)
        return;

    inc(n-1);
    cout<<n<<" ";
    
}


void dec(int n){
    if(n==0)
        return;

    cout<<n<<" ";
    dec(n-1);

}


bool sorted(int arr[],int n){

    if(n==1)
        return true;

    bool restArr=sorted(arr+1,n-1);
    return(arr[0]<arr[1] && restArr);
}



int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<sorted(a,n)<<endl;

    dec(n);
    inc(n);

    return 0;
}