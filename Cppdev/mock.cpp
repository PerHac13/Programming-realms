#include<iostream>
#include<string>

using namespace std;

class ClassItem {
    private:
        string name;
        int noOfStudent;

    public:
        // Parameterized constructor
        ClassItem(string name = "", int number = 0): name(name), noOfStudent(number) {} 
        // Function to print class details (for debugging)
        void print() const {
            cout << "Class Name: " << name << ", Number of Students: " << noOfStudent << endl;
        }
};

class school {
    private:
        string name;
        int noOfClass;
        string address;
        string principalName;   
        ClassItem* tmpClass;  // Pointer to an array of ClassItem

    public:
        // Constructor
        school(string name, int noOfClass, string add, string pName)
            : name(name), noOfClass(noOfClass), address(add), principalName(pName) {
            tmpClass = new ClassItem[noOfClass];  // Allocate array of ClassItem
            // for (int i = 0; i < noOfClass; ++i) {
            //     // Initialize each class with dummy data or prompt user for actual data
            //     tmpClass[i] = ClassItem("Class " + to_string(i+1), 30);  // Example initialization
            // }
        }

        // Destructor to clean up dynamically allocated memory
        ~school() {
            delete[] tmpClass;
        }

        // Function to print school details (for debugging)
        void print() const {
            cout << "School Name: " << name << endl;
            cout << "Principal Name: " << principalName << endl;
            cout << "Address: " << address << endl;
            cout << "Number of Classes: " << noOfClass << endl;
            for (int i = 0; i < noOfClass; ++i) {
                tmpClass[i].print();
            }
        }
};

int main() {
    school a("ABC School", 5, "XYZ123", "DEF");

    a.print();  // Print details of the school

    return 0;
}
