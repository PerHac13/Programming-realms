#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

// Base class demonstrating Abstraction
class LibraryItem {
protected:
    string title;
    string author;

public:
    LibraryItem(const string& t, const string& a) : title(t), author(a) {}
    virtual ~LibraryItem() = default;

    virtual void display() const = 0; // Pure virtual function
    virtual string getType() const = 0;
    virtual string getAdditionalInfo() const = 0; 

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

// Derived class demonstrating Inheritance
class Book : public LibraryItem {
private:
    int pages;

public:
    Book(const string& t, const string& a, int p) : LibraryItem(t, a), pages(p) {}

    void display() const override {
        cout << "Book: " << title << " by " << author << ", " << pages << " pages" << endl;
    }

    string getType() const override { return "Book"; }
    string getAdditionalInfo() const override { return to_string(pages); }
    int getPages() const { return pages; }
};

// Another derived class demonstrating Polymorphism
class Magazine : public LibraryItem {
private:
    string issue;

public:
    Magazine(const string& t, const string& a, const string& i) : LibraryItem(t, a), issue(i) {}

    void display() const override {
        cout << "Magazine: " << title << " by " << author << ", Issue: " << issue << endl;
    }

    string getType() const override { return "Magazine"; }
    string getAdditionalInfo() const override { return issue; }
    string getIssue() const { return issue; }
};

// Library class demonstrating Encapsulation
class Library {
private:
    vector<unique_ptr<LibraryItem>> items;

public:
    void addItem(unique_ptr<LibraryItem> item) {
        items.push_back(move(item));
    }

    void displayAllItems() const {
        for (const auto& item : items) {
            item->display();
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& item : items) {
                file << item->getType() << "," << item->getTitle() << "," << item->getAuthor() << ","
                     << item->getAdditionalInfo() << endl;
            }
            file.close();
            cout << "Library contents saved to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            items.clear();
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                string type, title, author, additionalInfo;
                
                if (getline(iss, type, ',') &&
                    getline(iss, title, ',') &&
                    getline(iss, author, ',') &&
                    getline(iss, additionalInfo)) {
                    
                    if (type == "Book") {
                        int pages = stoi(additionalInfo);
                        addItem(make_unique<Book>(title, author, pages));
                    } else if (type == "Magazine") {
                        addItem(make_unique<Magazine>(title, author, additionalInfo));
                    }
                }
            }
            file.close();
            cout << "Library contents loaded from " << filename << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    Library library;

    // Adding items using smart pointers
    library.addItem(make_unique<Book>("The Great Gatsby", "F. Scott Fitzgerald", 180));
    library.addItem(make_unique<Magazine>("National Geographic", "Various Authors", "June 2023"));

    int choice;
    string filename = "library.txt";

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Display all items\n";
        cout << "2. Add a book\n";
        cout << "3. Add a magazine\n";
        cout << "4. Save to file\n";
        cout << "5. Load from file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayAllItems();
                break;
            case 2: {
                string title, author;
                int pages;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter number of pages: ";
                cin >> pages;
                library.addItem(make_unique<Book>(title, author, pages));
                break;
            }
            case 3: {
                string title, author, issue;
                cout << "Enter magazine title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter issue: ";
                getline(cin, issue);
                library.addItem(make_unique<Magazine>(title, author, issue));
                break;
            }
            case 4:
                library.saveToFile(filename);
                break;
            case 5:
                library.loadFromFile(filename);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}