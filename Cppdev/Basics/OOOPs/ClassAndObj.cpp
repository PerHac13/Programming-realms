#include <iostream>

using std::string;

class Employee{
    public:
        int id;
        std::string name;
        float salary;

        Employee(int id, std::string name, float salary){
            this->id = id;
            this->name = name;
            this->salary = salary;
        }

        void display(){
            std::cout<<id<<' '<<name<<' '<<salary<<std::endl;
        }
};


int main(){

    return 0;
}