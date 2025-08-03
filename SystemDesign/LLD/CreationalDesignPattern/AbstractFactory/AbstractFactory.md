# Abstract Factory Pattern

```
The Abstract Factory Design Pattern provides a powerful way to manage the creation of related objects without specifying their concrete classes. It makes your system more scalable, maintainable, and easier to extend. Unlike the Factory Method, which works well for single products, the Abstract Factory is designed to handle families of related products with ease, making it an essential pattern in complex systems.
```

The name "Abstract Factory" comes from the concept of abstraction in programming. In simple terms, abstraction is the process of hiding the complex details of a system and exposing only the necessary parts.
In the Abstract Factory pattern, the "Abstract" part refers to the fact that the client code doesn’t know about the specific classes of objects being created. Instead of directly interacting with the concrete classes (like Honda, Toyota, or BMW), the client only knows about the factory interfaces (like VehicleFactory), which provide a method for creating objects without exposing the actual classes behind them.
Think of it like ordering a car from a dealership. As a customer, you don’t need to know the intricate details of how each car is built or which parts are used. You just choose the type of car you want (Honda, Toyota, BMW), and the factory (dealership) handles the rest. This is the abstraction at play: you only deal with the abstract factory interface, not the specific car details.

### Pro:

- [+] **Flexiblity**
- [+] **Maintainability**
- [+] **Decoupling**

---

#### Factory Method vs Abstract Factory:

- _Purpose_
  - F: Creates one type of object
  - A: Create families of related objects
- _Scope_
  - F: Focuses on creating a single product
  - A: Creates multiple related products
- _Abstraction Level_
  - F: Deals with one product at a time
  - A: Deals with groups of related products
- _Example_
  - F: A CarFactory creates one type at a time
  - A: A VehicleFactory creates cars, trucks, and bikes of the same brands
- _Flexibility_
  - F: Adding new products reqquires changing the factory
  - A: Adding new families doesn't affect existing code
- _Use case_
  - F: When you need to create a single object (e.g., one car model)
  - A: When you need to create related objects (e.g., different vehicles from the same brand)

---
