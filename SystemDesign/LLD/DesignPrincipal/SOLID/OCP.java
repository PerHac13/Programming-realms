abstract class Shape {
  abstract double calculateArea();
  // We can also use an interface instead of an abstract class
}

class Circle extends Shape {
 private
  double radius;
  @Override 
public double calculateArea() {
    return Math.PI * radius * radius;
  }
}

class Rectangle extends Shape {
 private
  double width;
 private
  double height;
  @Override 
public double calculateArea() {
    return width * height;
  }
}

// Adding a new shape without modifying existing code
class Triangle extends Shape {
 private
  double base;
 private
  double height;
  @Override 
public double calculateArea() {
    return 0.5 * base * height;
  }
}

public class OCP {
  public static void main(String[] args) {
    Shape circle = new Circle();
    Shape rectangle = new Rectangle();
    Shape triangle = new Triangle();
    
    System.out.println("Circle Area: " + circle.calculateArea());
    System.out.println("Rectangle Area: " + rectangle.calculateArea());
    System.out.println("Triangle Area: " + triangle.calculateArea());
  }
}



// // Incorrect approach
// class Shape {
//  private
//   String type;
//  public
//   double calculateArea() {
//     if (type.equals("circle")) {
//       // Circle area calculation
//     } else if (type.equals("rectangle")) {
//       // Rectangle area calculation
//     }
//     // Adding a triangle requires modifying this method
//   }
// }
