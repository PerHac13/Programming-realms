#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

// Student class
class Student {
private:
    std::string name;
    int age;
public:
    Student(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Student Name: " << name << ", Age: " << age << std::endl;
    }

    std::string getName() const { return name; }
    int getAge() const { return age; }

    void save(std::ofstream& ofs) const {
        ofs << name << " " << age << std::endl;
    }
};

// ClassRoom class
class ClassRoom {
private:
    std::string teacherName;
    std::vector<std::shared_ptr<Student>> students;
public:
    ClassRoom(const std::string& teacherName) : teacherName(teacherName) {}

    void addStudent(const std::string& studentName, int studentAge) {
        students.push_back(std::make_shared<Student>(studentName, studentAge));
    }

    void display() const {
        std::cout << "Class Teacher: " << teacherName << std::endl;
        std::cout << "Students:" << std::endl;
        for (const auto& student : students) {
            student->display();
        }
    }

    std::string getTeacherName() const { return teacherName; }

    void save(std::ofstream& ofs) const {
        ofs << teacherName << std::endl;
        ofs << students.size() << std::endl;
        for (const auto& student : students) {
            student->save(ofs);
        }
    }
};

// School class
class School {
private:
    std::vector<std::shared_ptr<ClassRoom>> classrooms;
public:
    void addClassRoom(const std::string& teacherName) {
        classrooms.push_back(std::make_shared<ClassRoom>(teacherName));
    }

    void addStudentToClassRoom(int classIndex, const std::string& studentName, int studentAge) {
        if (classIndex >= 0 && classIndex < classrooms.size()) {
            classrooms[classIndex]->addStudent(studentName, studentAge);
        } else {
            std::cout << "Invalid Class Index!" << std::endl;
        }
    }

    void display() const {
        for (size_t i = 0; i < classrooms.size(); ++i) {
            std::cout << "Class " << i + 1 << ":\n";
            classrooms[i]->display();
            std::cout << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (!ofs) {
            std::cout << "Error opening file!" << std::endl;
            return;
        }
        ofs << classrooms.size() << std::endl;
        for (const auto& classroom : classrooms) {
            classroom->save(ofs);
        }
        ofs.close();
        std::cout << "Data saved to " << filename << std::endl;
    }
};

// Menu-driven interface
void displayMenu() {
    std::cout << "\n--- School Management System ---\n";
    std::cout << "1. Add Class Room\n";
    std::cout << "2. Add Student to Class Room\n";
    std::cout << "3. Display All Classes\n";
    std::cout << "4. Save Data to File\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    School school;
    int choice;
    std::string teacherName, studentName, filename;
    int studentAge, classIndex;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter Class Teacher Name: ";
                std::cin.ignore();
                std::getline(std::cin, teacherName);
                school.addClassRoom(teacherName);
                break;
            }
            case 2: {
                std::cout << "Enter Class Index (starting from 1): ";
                std::cin >> classIndex;
                std::cout << "Enter Student Name: ";
                std::cin.ignore();
                std::getline(std::cin, studentName);
                std::cout << "Enter Student Age: ";
                std::cin >> studentAge;
                school.addStudentToClassRoom(classIndex - 1, studentName, studentAge);
                break;
            }
            case 3: {
                school.display();
                break;
            }
            case 4: {
                std::cout << "Enter filename to save data: ";
                std::cin >> filename;
                school.saveToFile(filename);
                break;
            }
            case 5: {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again." << std::endl;
                break;
            }
        }

    } while (choice != 5);

    return 0;
}
