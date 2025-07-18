abstract class Vehicle {
  // Common vehicle behaviors
 public
  void move() {
    // Movement logic
  }
}

abstract class EngineVehicle extends Vehicle {
 public
  void startEngine() {
    // Engine starting logic
  }
}

abstract class NonEngineVehicle extends Vehicle {
  // No engine-related methods
}

class Car extends EngineVehicle {
  @Override public void startEngine() {
    // Car-specific engine starting logic
  }
}

class Bicycle extends NonEngineVehicle {
  // Bicycle-specific methods
  // No need to implement engine-related methods
}

public class Main {
 public
  static void main(String[] args) {
    // Using EngineVehicle
    EngineVehicle car = new Car();
    car.startEngine();  // Output: Car-specific engine starting logic
    car.move();         // Output: Movement logic


    // Using NonEngineVehicle
    NonEngineVehicle bicycle = new Bicycle();
    bicycle.move();  // Output: Movement logic
  }
}

// class Vehicle {
//  public
//   void startEngine() {
//     // Engine starting logic
//   }
// }

// class Car extends Vehicle {
//   @Override public void startEngine() {
//     // Car-specific engine starting logic
//   }
// }

// class Bicycle extends Vehicle {
//   @Override public void startEngine() {
//     // Problem: Bicycles don't have engines!
//     throw new UnsupportedOperationException("Bicycles don't have engines");
//   }
// }

// public class Main {
//  public
//   static void main(String[] args) {
//     // Creating objects of different subclasses
//     Vehicle car = new Car();
//     Vehicle bicycle = new Bicycle();
//     // Using polymorphism
//     System.out.println("Car:");
//     car.startEngine();  // Output: Car engine started.
//     System.out.println("nBicycle:");
//     try {
//       bicycle.startEngine();  // Throws UnsupportedOperationException
//     } catch (UnsupportedOperationException e) {
//       System.out.println("Error: " + e.getMessage());
//     }
//   }
// }