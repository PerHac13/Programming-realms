#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>

class Student {
private:
    std::string name;
    int age;
public:
    Student(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Student Name: " << name << ", Age: " << age << std::endl;
    }

    std::string toJSON() const {
        return "{ \"name\": \"" + name + "\", \"age\": " + std::to_string(age) + " }";
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

    std::string toJSON() const {
        std::string json = "{ \"classNumber\": " + std::to_string(classNumber) + ", \"classTeacher\": \"" + classTeacher + "\", \"students\": [";
        for (size_t i = 0; i < students.size(); ++i) {
            json += students[i]->toJSON();
            if (i < students.size() - 1) json += ", ";
        }
        json += "] }";
        return json;
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

    std::string getName() const {
        return name;
    }

    std::vector<std::shared_ptr<Class>>& getClasses() {
        return classes;
    }

    void displaySchoolInfo() const {
        std::cout << "School Name: " << name << std::endl;
        for (const auto& schoolClass : classes) {
            schoolClass->displayClassInfo();
        }
    }

    void saveToFileJSON() const {
        std::string filename = name;
        std::replace(filename.begin(), filename.end(), ' ', '_');
        filename += ".json";

        std::ofstream file(filename);
        if (file.is_open()) {
            file << "{ \"schoolName\": \"" << name << "\", \"classes\": [";
            for (size_t i = 0; i < classes.size(); ++i) {
                file << classes[i]->toJSON();
                if (i < classes.size() - 1) file << ", ";
            }
            file << "] }";
            file.close();
            std::cout << "School data saved to file: " << filename << std::endl;
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }
};

std::shared_ptr<School> createSchool() {
    std::string schoolName;
    std::cout << "Enter the school name: ";
    std::getline(std::cin, schoolName);
    return std::make_shared<School>(schoolName);
}

void schoolMenu(std::shared_ptr<School> school) {
    while (true) {
        std::cout << "\nSchool: " << school->getName() << std::endl;
        std::cout << "1. Create a new class\n";
        std::cout << "2. Select an existing class\n";
        std::cout << "3. Save and Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string teacher;
            int classNumber;
            std::cout << "Enter class teacher name: ";
            std::getline(std::cin, teacher);
            std::cout << "Enter class number: ";
            std::cin >> classNumber;
            std::cin.ignore();
            std::shared_ptr<Class> newClass = std::make_shared<Class>(teacher, classNumber);
            school->addClass(newClass);
            std::cout << "Class created successfully!\n";
        } else if (choice == 2) {
            auto& classes = school->getClasses();
            if (classes.empty()) {
                std::cout << "No classes available.\n";
                continue;
            }
            std::cout << "Available classes:\n";
            for (size_t i = 0; i < classes.size(); ++i) {
                std::cout << i + 1 << ". Class Number: " << classes[i]->toJSON() << std::endl;
            }
            std::cout << "Select a class by number: ";
            int classChoice;
            std::cin >> classChoice;
            std::cin.ignore();

            if (classChoice > 0 && classChoice <= classes.size()) {
                std::shared_ptr<Class> selectedClass = classes[classChoice - 1];
                while (true) {
                    std::cout << "\n1. Add student to class\n";
                    std::cout << "2. Display class info\n";
                    std::cout << "3. Go back\n";
                    int studentChoice;
                    std::cin >> studentChoice;
                    std::cin.ignore();
                    if (studentChoice == 1) {
                        std::string studentName;
                        int age;
                        std::cout << "Enter student name: ";
                        std::getline(std::cin, studentName);
                        std::cout << "Enter student age: ";
                        std::cin >> age;
                        std::cin.ignore();
                        selectedClass->addStudent(std::make_shared<Student>(studentName, age));
                        std::cout << "Student added successfully!\n";
                    } else if (studentChoice == 2) {
                        selectedClass->displayClassInfo();
                    } else if (studentChoice == 3) {
                        break;
                    }
                }
            } else {
                std::cout << "Invalid class selection.\n";
            }
        } else if (choice == 3) {
            school->saveToFileJSON();
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    std::vector<std::shared_ptr<School>> schools;
    while (true) {
        std::cout << "\nMain Menu\n";
        std::cout << "1. Create a new school\n";
        std::cout << "2. Select an existing school\n";
        std::cout << "3. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            schools.push_back(createSchool());
        } else if (choice == 2) {
            if (schools.empty()) {
                std::cout << "No schools available.\n";
                continue;
            }
            std::cout << "Available schools:\n";
            for (size_t i = 0; i < schools.size(); ++i) {
                std::cout << i + 1 << ". " << schools[i]->getName() << std::endl;
            }
            std::cout << "Select a school by number: ";
            int schoolChoice;
            std::cin >> schoolChoice;
            std::cin.ignore();

            if (schoolChoice > 0 && schoolChoice <= schools.size()) {
                schoolMenu(schools[schoolChoice - 1]);
            } else {
                std::cout << "Invalid school selection.\n";
            }
        } else if (choice == 3) {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
