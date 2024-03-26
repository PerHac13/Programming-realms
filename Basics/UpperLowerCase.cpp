#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string str="asbjkcbdAbsuwajdnUGFTYGUsnkjadh";
    cout<<str<<endl;
    

    //convert into upper case
    for(int i=0; i<str.length();i++){
        
        if(str[i]>='a' && str[i]<='z')
        str[i]-=32;
    }

    cout<<str<<endl;

    //covert into lower case
    for(int i=0; i<str.length();i++){
        
        if(str[i]>='A' && str[i]<='Z')
        str[i]+=32;
    }

    cout<<str<<endl;

    


    //shortcuts

    //to upper
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<str<<endl;

    //to lower
    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<str<<endl;


    return 0;
}