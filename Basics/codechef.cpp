#include <iostream>
using namespace std;



int main() {
	// your code goes here
	long t,x,y,v;
	cin>>t;
	while(t--){
	    cin>>x>>y;
	    v=998244353*x/(x+y);
	    cout<<v<<endl;
	}
	return 0;
}

//tsort
#include<bits/stdc++.h>
using namespace std;
int main()
{

        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
          cin>>a[i];
            sort(a,a+n);
            for(int i=0;i<n;i++)
            cout<<a[i]<<'\n';
    return 0;
}


//NOSEQ codechef starters 72s
#include <bits/stdc++.h>
using namespace std;

long long myFunc(long long a, long long b) {
  if (b == 0)
  return 1;
  long long res = myFunc(a, b / 2);
  if (b % 2)
  return res * res * a;
  else
  return res * res;
}


int main() {
  int ts;
  cin>>ts;
  
  lable:while(ts-->0)
  {
    long long n,k,s,i,tp,sum=0;
    cin>>n>>k>>s;
    tp=s;
  
    int b[n];
    for(i=0;i<n;i++)
    {
      long long rm=s%k;
      if(rm!=0 && rm!=1 && rm!=k-1)
      {
        cout<<-2<<endl;
        goto lable;
      }
      if(rm==k-1 && k!=2)
      rm=-1;
      b[i]=rm;
      s=(s-rm)/k;
    }

      for(i=0;i<n;i++)
        sum+=(b[i]*myFunc(k,i));
      if(sum!=tp)
      {
      cout<<-2<<endl;
      goto lable;
      }

      for(i=0;i<n;i++)
      cout<<b[i]<<" ";
      cout<<endl;
      }


  return 0;
}