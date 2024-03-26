#include<iostream>

using namespace std;

int main(){

    int n,max=0,k;

    cout<<"Enter the size of array: ";
    cin>>n;

    // taking array input
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl<<"Enter index till you want to find max. no.: ";
    cin>>k;

    // printing max no.
    for(int j=0;j<k;j++){
        if(a[j]>max)
        max=a[j];
    }

    cout<<"Max. no. till index "<<k<<" is "<<max<<endl;

    return 0;
}