#include<iostream>

using namespace std;

int main(){

    int d;

    cout<<"Enter the numbers of days: ";
    cin>>d;

    // taking array input
    int a[d+1];
    for(int i=0;i<d;i++){
        cin>>a[i];
    }
    a[d+1]=-1;

    //record breaker
    if(d==1){
        cout<<"1"<<endl;

        return 0;
    } 


    int rd=0,mx=-1;
    for(int i=1;i<d;i++){
        
        if(a[i]>a[i+1] && a[i]>mx)
        rd++;

        mx=max(mx,a[i]);
    }

    cout<<"Number of Record breaking : "<<rd;

    return 0;
}