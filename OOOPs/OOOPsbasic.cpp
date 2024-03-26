#include<bits/stdc++.h>

using namespace std;

class student{
    string name;    //private as default

    public:         // public after access from outside
    int age;
    bool gender;

    student(){                        //Default constructor function
        cout<<"default constructor"<<endl;
    }

    student(string s,int a,bool g){  //parameterized constructor function
        name=s;
        age=a;
        gender=g;
    }

    student(student &a){            //copy constructor function
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    ~student(){                     //destructor function
        cout<<"Destructor called"<<endl;
    }

    void setName(string s){         //setter function
        name=s;
    }
    void getName(){                 //getter function
        cout<<name<<endl;
    }

    void printInfo(){
        cout<< "Name = "<<name<<endl;
        cout<< "Age = "<<age<<endl;
        cout<< "Gender = "<<gender<<endl;
    }

    bool operator == (student &a){      //overload function fo
        if(name==a.name && age==a.age && gender==a.gender)
        return true;
        return false;
    }
};

int main(){

    student b;
    b.setName("Rohit");
    b.age=20;
    b.gender=1;

    student c("Riyaz",18,1);
    student d(b);
    student e=c;

    b.printInfo();
    c.printInfo();
    d.printInfo();
    e.printInfo();

    student a[3];
    for(int i=0;i<3;i++){
        string s;
        cout<< "Name = ";
        cin>>s;
        a[i].setName(s);
        cout<< "Age = ";
        cin>>a[i].age;
        cout<< "Gender = ";
        cin>>a[i].gender;
    }

    for(int i=0;i<3;i++){
        a[i].printInfo();
    }

    if(e==c)        //overload
    cout<<"same"<<endl;
    else
    cout<<"not same"<<endl;

    return 0;
}