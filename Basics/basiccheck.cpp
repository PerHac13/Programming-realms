#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void add(int a[],int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;

    int x[n1],y[n2];
    for(int i=0;i<n1;i++)
        x[i]=a[s+i];
    for(int i=0;i<n2;i++)
        y[i]=a[mid+1+i];

    int i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(x[i]<y[j]){
            a[k]=x[i];
            k++;i++;
        }
        else{
            a[k]=y[j];
            k++;j++;
        }
    }

    while(i< n1){
        a[k]=x[i];
            k++;i++;
    }
    while(j<n2){
        a[k]=y[j];
            k++;j++;
    }


}



void div(int a[],int s,int e){
    if(s<e){
        int mid=(s+e)/2;

        div(a,s,mid);
        div(a,mid+1,e);

        add(a,s,mid,e);

    }
}



int main(){
    
    int a[]={2,3,11,5,6,7,10,4,11};

    div(a,0,9);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}