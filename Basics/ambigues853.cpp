#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n!=0)
	{
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
        for(int i=0; i<n; i++)
	    {
	        cout<<a[i];
	    }
	    int b[n];
	    for(int i=0; i<n; i++)
	    {
	        int p=a[i];
	        b[p-1]=i+1;
	    }
        for(int i=0; i<n; i++)
	    {
	        cout<<b[i];
	    }
	    int f=0;
	    for(int i=0; i<n; i++)
	    {
	        if(a[i]!=b[i])
	        {
	            f=1;
	            break;
	        }
	    }
	    cout<<(f==1? "not ambiguous" : "ambiguous")<<endl;
	    cin>>n;
	}
	return 0;
}