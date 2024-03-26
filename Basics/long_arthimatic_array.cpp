#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;

int main(){

    int n;

    cout<<"Enter the size of array: ";
    cin>>n;

    // taking array input
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //size 
    int pd=0,ans=2,curr=2;
    pd=a[1]-a[0];
    for(int i=2;i<n;i++){
        if(pd==a[i]-a[i-1]){
                curr++;
                ans=max(curr,ans);
        }
        else{
            pd=a[i]-a[i-1];
            curr=2;
        }
    }

    cout<<"The size of longest arthimatic array : "<<ans<<endl;

    return 0;
}