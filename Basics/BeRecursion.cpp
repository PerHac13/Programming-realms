#include<iostream>
#include<string>

using namespace std;

string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string code=keypadArr[ch-'0'];
    string ros= s.substr(1);

    for (int i = 0; i<code.size(); i++)
    {
        keypad(ros,ans+code[i]);
    }
    
}

void substr(string s,string ans){

    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);

    substr(ros,ans);
    substr(ros,ans+ch);
    substr(ros,ans+to_string(code));
}

string moveXtolast(string  s){
    if(s.size()==0)
        return "";

    char ch=s[0];
    string ans=moveXtolast(s.substr(1));

    if(ch=='x')
        return ans+ch;
    return ch+ans;
}

string removeDup(string s){
    if(s.size()==0)
        return "";

    char fst=s[0];
    string ans=removeDup(s.substr(1));

    if(fst==ans[0])
        return ans;
    return fst+ans;
}

void towerofHonoi(int n,char src,char dest,char helper){

    if(n==0){
        return;
    }

    towerofHonoi(n-1,src,helper,dest);

    cout<<"Move from "<<src<<" to "<<dest<<endl;

    towerofHonoi(n-1,helper,dest,src);


}

void replacePi(string s){
    if(s.length()==0)
        return;

    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

void revstr(string s){

    if(s.length()==0)
        return;

    string ros=s.substr(1);
    revstr(ros);
    cout<<s[0];
}


int main(){

    string str;

    cin>>str;

    revstr(str);

    cout<<endl;
    cin>>str;


    replacePi(str);

    int n;
    cin>>n;
    cout<<endl;

    towerofHonoi(n,'A','C','B');

    cout<<endl;
    cin>>str;
    cout<<removeDup(str)<<endl;

    cin>>str;
    cout<<moveXtolast(str)<<endl;

    cin>>str;
    substr(str,"");
    cout<<endl;

    cin>>str;
    keypad(str,"");
    cout<<endl;


    return 0;
}