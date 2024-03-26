#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    //declaration

    string s1,s5(5,'n'),s3="ShaikhAbdullah";
    string s4;
    cin>>s1;
    getline(cin,s4);


    cout<<s1<<endl;
    cout<<s5<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;


    //addition
    string s6="fam",s7="ily";
    cout<<s6+s7<<endl;
    s6.append(s7);      //s6=s6+s7

    //clear
    string abc="hjbhjgygg gyfyg fytdt";
    cout<<abc<<endl;
    abc.clear();
    cout<<abc<<endl;

    //compare
    string st1="abc",st2="xyz";
    cout<<st2.compare(st1)<<endl;

    //empty st2.empty();

    //to remove
    string st3="nincompoop";
    st3.erase(3,2);
    cout<<st3<<endl;

    //to find
    cout<<st3.find("poo")<<endl;

    //to insert
    st3.insert(3,"co");
    cout<<st3<<endl;

    //to find size
    cout<<st3.length()<<endl;   //can also use st3.size()

    //to extract sub string
    string s;
    s=st3.substr(6,4);

    //to convert string to int
    string si="786";
    int x=stoi(si);
    cout<<x+2<<endl;

    //to convert int to string
    cout<< to_string(x) + "2"<<endl;

    //sorting  header file algorithm
    string ss="safdsgfzshggsxchjewgfiergvervgr"; 
    sort(ss.begin(),ss.end());
    cout<<ss<<endl;


    return 0;
}