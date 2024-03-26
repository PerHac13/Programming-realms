#include<bits/stdc++.h>


using namespace std;

void sort012(int a[], int n)
    {
        // code here 
        int z=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)
            z++;
            else if(a[i]==1)
            b++;
            else
            c++;
        }
        int j=0;
        while(z--){
            a[j]=0;
            j++;
        }
        while(b--){
            a[j]=1;
            j++;
        }while(c--){
            a[j]=2;
            j++;
        }
    }

int main(){

   int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort012(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}