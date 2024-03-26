#include<iostream>

using namespace std;

void dnfSort(int arr[],int n){

    int low=0,mid=0,high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        if(arr[mid]==1)
            mid++;

        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }


    return ;
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    dnfSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}