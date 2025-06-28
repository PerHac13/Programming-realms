package com.example.demo;

// abstract class Computer {
//     public abstract void compute();
// }
// abstract class can have both abstract and non-abstract methods
// if there is only abstract methods, it is called an interface
interface Computer {
    void compute(); // abstract method
    int MAX_MEMORY = 1024; // constant (public static final by default)
    // waht is final?
    // final means the value cannot be changed, it is a constant

    // what if i what variable in an interface? that can be declared by its implemented class
    
}
interface Portable {
    void carry(); // abstract method
}

class Laptop implements Computer, Portable {
    @Override
    public void compute() {
        System.out.println("Computing on a laptop");
    }
    @Override
    public void carry() {
        System.out.println("Carrying a laptop");

    }
}

class Desktop implements Computer {
    @Override
    public void compute() {
        System.out.println("Computing on a desktop");
    }
}

class Dev {
    public void code(Computer computer) {
        System.out.println("Coding on a computer");
        computer.compute();
    }
}

public class A {
    public static void main(String[] args) {
        Dev dev = new Dev();
        Computer laptop = new Laptop();
        Computer desktop = new Desktop();

        dev.code(laptop);
        dev.code(desktop);
    }
}