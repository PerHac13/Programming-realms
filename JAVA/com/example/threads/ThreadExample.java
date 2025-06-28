package com.example.threads;

class A extends Thread {
    public void display() {
        int t = 5; // Number of times to print
        for(int i = 0; i < t; i++){
        System.out.println("Hello from class A");
        try {
            Thread.sleep(1000); // Sleep for 1 second
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted: " + e.getMessage());
        }}
    }
    public void run() {
        display();
    }
}

class B extends Thread {
    public void display() {
        int t = 5; // Number of times to print
        for(int i = 0; i < t; i++){
        System.out.println("Hello from class B");}
    }
    public void run() {
        display();
    }
}
class C implements Runnable {
    public void display() {
        int t = 5; // Number of times to print
        for(int i = 0; i < t; i++){
        System.out.println("Hello from class C");}
    }
    public void run() {
        display();
    }
}
class D implements Runnable {
    public void display() {
        int t = 5; // Number of times to print
        for(int i = 0; i < t; i++){
        System.out.println("Hello from class D");}
    }
    public void run() {
        display();
    }
}

public class ThreadExample {
    public static void main(String[] args) {
        A objA = new A();
        B objB = new B();
        A objA2 = new A(); // Create another instance of A

        objA2.setPriority(Thread.MAX_PRIORITY); // Set highest priority for objC
        System.out.println("Priority of objA2: " + objA2.getPriority()); // Print

        objA.start(); // Start thread A
        objB.start(); // Start thread B

        C objC = new C();
        D objD = new D();
        Thread threadC = new Thread(objC);
        Thread threadD = new Thread(objD);

        threadC.start(); // Start thread C
        threadD.start(); // Start thread D



    }
}