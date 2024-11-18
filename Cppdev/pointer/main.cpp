#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

class Student {
private:
    std::string name;
    int age;
public:
    Student(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Student Name: " << name << ", Age: " << age << std::endl;
    }

    std::string getInfo() const {
        return "Student Name: " + name + ", Age: " + std::to_string(age);
    }
};

class Class {
private:
    std::string classTeacher;
    int classNumber;
    std::vector<std::shared_ptr<Student>> students;
public:
    Class(const std::string& classTeacher, int classNumber)
        : classTeacher(classTeacher), classNumber(classNumber) {}

    void addStudent(const std::shared_ptr<Student>& student) {
        students.push_back(student);
    }

    void displayClassInfo() const {
        std::cout << "Class Number: " << classNumber << ", Class Teacher: " << classTeacher << std::endl;
        std::cout << "Students: " << std::endl;
        for (const auto& student : students) {
            student->display();
        }
    }

    std::string getClassInfo() const {
        std::string info = "Class Number: " + std::to_string(classNumber) + ", Class Teacher: " + classTeacher + "\n";
        info += "Students:\n";
        for (const auto& student : students) {
            info += student->getInfo() + "\n";
        }
        return info;
    }
};

class School {
private:
    std::string name;
    std::vector<std::shared_ptr<Class>> classes;
public:
    School(const std::string& name) : name(name) {}

    void addClass(const std::shared_ptr<Class>& schoolClass) {
        classes.push_back(schoolClass);
    }

    void displaySchoolInfo() const {
        std::cout << "School Name: " << name << std::endl;
        for (const auto& schoolClass : classes) {
            schoolClass->displayClassInfo();
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "School Name: " << name << "\n";
            for (const auto& schoolClass : classes) {
                file << schoolClass->getClassInfo() << "\n";
            }
            file.close();
            std::cout << "School data saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }
};

int main() {
    // Creating a school
    std::shared_ptr<School> mySchool = std::make_shared<School>("ABC High School");

    // Creating classes
    std::shared_ptr<Class> class1 = std::make_shared<Class>("Mr. Smith", 10);
    std::shared_ptr<Class> class2 = std::make_shared<Class>("Mrs. Johnson", 12);

    // Creating students
    std::shared_ptr<Student> student1 = std::make_shared<Student>("John Doe", 15);
    std::shared_ptr<Student> student2 = std::make_shared<Student>("Jane Doe", 16);
    std::shared_ptr<Student> student3 = std::make_shared<Student>("Bob Smith", 17);

    // Adding students to classes
    class1->addStudent(student1);
    class1->addStudent(student2);
    class2->addStudent(student3);

    // Adding classes to the school
    mySchool->addClass(class1);
    mySchool->addClass(class2);

    // Displaying school info
    mySchool->displaySchoolInfo();

    // Saving school data to a file
    mySchool->saveToFile("school_data.txt");

    return 0;
}
