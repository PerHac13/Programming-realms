// Parent class
class Vehicle {
  void start() {
    System.out.println("Starting a generic vehicle");
  }
}

// Subclasses overriding the start method
class Car extends Vehicle {
  @Override
  void start() {
    System.out.println("Starting a car");
  }
}

class Bike extends Vehicle {
  @Override
  void start() {
    System.out.println("Starting a bike");
  }
}

class Truck extends Vehicle {
  @Override
  void start() {
    System.out.println("Starting a truck");
  }
}

public class Main {
  public static void main(String[] args) {
    Vehicle myVehicle;
    // Assign a Car object to the Vehicle reference
    myVehicle = new Car();
    myVehicle.start(); // Output: Starting a car

    // Assign a Bike object to the Vehicle reference
    myVehicle = new Bike();
    myVehicle.start(); // Output: Starting a bike

    // Assign a Truck object to the Vehicle reference
    myVehicle = new Truck();
    myVehicle.start(); // Output: Starting a truck
  }
}