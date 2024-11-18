#include <iostream>
#include <string>

// 1. Encapsulation: Bundling of data and methods that operate on that data within a single unit (class).
class BankAccount {
private:
    double balance;  // Private member, not accessible from outside the class

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

// 2. Abstraction: Hiding complex implementation details and showing only the necessary features of an object.
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual void draw() const = 0;    // Pure virtual function
};

// 3. Inheritance: Allows a class to inherit properties and methods from another class.
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// 4. Polymorphism: Ability of objects of different classes to respond to the same method call, possibly in different ways.
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }

    void draw() const override {
        std::cout << "Drawing a square" << std::endl;
    }
};

// 5. Composition: Building complex objects from simpler ones.
class Car {
private:
    class Engine {  // Nested class, demonstrating composition
    public:
        void start() {
            std::cout << "Engine started" << std::endl;
        }
    };

    Engine engine;

public:
    void startCar() {
        engine.start();
        std::cout << "Car is ready to go" << std::endl;
    }
};

int main() {
    // Demonstrating encapsulation
    BankAccount account(1000);
    account.deposit(500);
    std::cout << "Balance: $" << account.getBalance() << std::endl;

    // Demonstrating polymorphism
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Square(4);

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << std::endl;
    }

    // Demonstrating composition
    Car myCar;
    myCar.startCar();

    // Clean up
    delete shapes[0];
    delete shapes[1];

    return 0;
}