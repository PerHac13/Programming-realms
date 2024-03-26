#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N],h[N],k[N];

int frogJump(int i){
   if(i==0)return 0;
   if(dp[i]!=-1)return dp[i];
   int cost=INT_MAX;
   for(int j=1;j<=k[i];++j){
      if(i-j>=0){
         cost=min(cost,frogJump(i-j)+abs(h[i]-h[i-j]));
      }
   }
   return dp[i]=cost;
}
// k store max number of jumplength;
int main(){

    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>h[i];
    for(int i=0;i<n;++i)cin>>k[i];
    cout<<frogJump(n);

   return 0;
}