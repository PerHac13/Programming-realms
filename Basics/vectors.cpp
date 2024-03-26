#include <iostream>
#include<bits/stdc++.h>
#include<vector>

#define pb push_back

using namespace std;

int main(){

    vector<int> v;
    v.push_back(1);
    v.pb(2);
    v.pb(4);
    v.pb(7);
    v.pb(90);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }//1 2 4

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }//1 2 4

    for(auto element:v){
        cout<<element<<endl;
    }// 1 2 4
    
    v.pop_back(); //1 2

    vector<int>v2(5);
    vector<int>v3(5,30);

    swap(v,v3);

    for(auto element:v){
        cout<<element<<endl;
    }// 1 2 4
    for(auto element:v3){
        cout<<element<<endl;
    }// 1 2 4

    sort(v.begin(),v.begin());





    return 0;
}