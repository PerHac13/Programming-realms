#include <bits/stdc++.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

/* PerHac */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* LOOPS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

/* VECTOR */
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }
#define coutY cout<<"YES"<<endl
#define coutN cout<<"NO"<<endl
#define nl cout<<endl
#define cout(a) cout << a <<endl

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

/* SELF define FUNCTION*/
int floor(int x,int z){
    if(x%z==0)
     return abs(x/z);
     else
     return 1+abs(x/z);
}

/* Array */
#define ain(i,s,e,arr) for(long long int i=s;i<e;i++){cin>>arr[i];}
#define aout(i,s,e,arr) for(long long int i=s;i<e;i++){cout<<arr[i]<<" ";}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;



void sol(){

   


}


int main(){

   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);


   int t;
   cin>>t;
   while(t--)
    sol();


 return 0;
}

