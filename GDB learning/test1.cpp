#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main(void){

    string str="Hello World";
    cout<<str<<endl;

    vector<string> v={"Hello","World"};
    for(auto i:v){
        cout<<i<<endl;
    }

    return 0;
}