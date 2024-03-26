#include<iostream>

using namespace std;



/*KNAPSACK Problem
    put n item with given weight and value in a knapsack of capacity W to get the maximum total value in the knapsack*/
int knapsack(int value[],int wt[],int n,int W){

    if(n==0 ||W==0)
        return 0;

    if(wt[n-1]>W)
        knapsack(value,wt,n-1,W);

        int b;
        b=max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value,wt,n-1,W));
    
    return b;
}


/*Find the number of ways in which n friends can remain single or can be paired up*/
int coupling(int n){

    if(n==0 || n==1 || n==2)
        return n;

    return coupling(n-1)+coupling(n-2)*(n-1);

}



/*Given a 2*n board and tiles of size 2*1, count the number of ways to tile the given board using these tiles*/
int tilingways(int n){
    if(n==0 || n==1){                //base condition 
        return n;
    }

    return tilingways(n-1)+tilingways(n-2);
}


int main(){

    int n;
    cin>>n;
    cout<< tilingways(n) <<endl;

    cout<<coupling(n)<<endl;

    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;

    cout<<knapsack(value,wt,3,W)<<endl;





    return 0;
}