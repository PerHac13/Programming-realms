# OOOPS

It helps us make more structured project.

## Classes and Object

- **Class** is a blueprint of the object (car design), properties and behaviour.
- **Object** is instance of class (car)

- A class provides the structure and design, while objects bring that structure to life with specific data.

### Constructor

- It help us to initialized the objects of class
- special methods
- Automatic invocation (invoke)
- No Return Type
- Overloading support

```
- Contructor from parent class can be called using super() in java
- carefully implement copy contructor to avoid shallow copy, to deep copy
- First parent contructor is called before child
- can have return but can not have return value
```

#### Its types

- Default
- Parameter
- Copy
- Private

```
Note: A private contructor is used to restrict object creation from outside of class. It is commonly used in Singleton Design Pattern.
```

### this keyword

- refering to the instance object
- Using the "this" keyword for constructor chaining allows one constructor to invoke another constructor within the same class. This reduces code duplication and centralizes initialization logic, making the code easier to maintain. It also ensures that all constructors eventually delegate to a common initialization point
- Return the current object
- Passing the current object

```
- Disambiguation
- Chaining
- Passing Reference
- Dynamic bonding
```

<br>
<br>

# OOPs Pillar

## Polymorphism

Multiple + form

#### Its type

- **_Compile time (static) Polymorphism_** : method overloading or operator overloading
- **_Runtime (Dynamic) Polymorphism_** : method overriding

#### Pros & Cons

- [+] Code Reusablity
- [+] Flexibility
- [+] Extentiblity
- [-] Complex Debugging
- [-] Minor Overhead in case of Runtime

<br>

## Inheritance

Inherit properties, methods from parent class

#### Its types

- **_Single Inheritance_**
- **_Multiple Inhertance_**
- **_Hierarchical Inheritance_**
- **_Multiple Inheritance_**
- **_Hybrid Inheritance_**

#### Pros & Cons

- [+] Code Reusablity
- [+] Ease of Maintainablity
- [+] Extentiblity
- [+] Support Polymorphism
- [-] Increased Coupling
- [-] Complexity
- [-] Reduce Flexibility

<br>

## Encapsulation

It involves bundling data (variables) and methods (functions) that operate on the data into a single unit called a class.

#### Its Feature

- **_Data Hiding_**
- **_Modularity_**
- **_Security_**
- **_Flexibility_**

#### Pros & Cons

- [+] Improve Data Security
- [+] Ease of Maintainablity
- [+] Increase Flexibility
- [+] Enhanced Readability
- [-] Slight Overhead
- [-] Complexity

## Abstraction

Abstraction allows us to focus on defining the what of an object (its behavior) while hiding the how of the object (its implementation).

This approach not only reduces code redundancy by centralizing shared logic but also enhances the flexibility and scalability of the system.

### Abstraction helps to:

- Create a scalable design where adding new animals only involves defining a new subclass or implementing a new interface.

- Ensure consistency across all animal types by enforcing common methods like makeSound() and sleep().

- Facilitate polymorphism, enabling us to write code that can interact with any animal in a generic way, regardless of its specific type.

### Ways to achieve Abstraction

- **_Abstract Class_**
- **_Interfaces_**

### Abstract Class

An abstract class acts as a blueprint for other classes, providing a foundation for shared behavior while allowing subclasses to define specific implementations.
It can have abstract (need to define) method as well as concrete (pre-define) method

#### Pros & Cons

- [+] Improve Code Maintainablity
- [+] Enhanced Flexibility
- [+] Better Code Reusability
- [+] Increased Security
- [-] Complexity in Design (Irrelevant Methids, Confusion, Errors)
- [-] Overhead (Overhead Performance, Readability)

### Interface

An interface defines a contract or a set of rules that a class must adhere to. It contains abstract methods that specify what a class should do, without dictating how it should be done.

Unlike abstract classes, interfaces focus purely on behavior and do not include state (fields). Starting from Java 8, interfaces can also include default and static methods, enabling the addition of shared logic without breaking existing implementations.

Interfaces are a powerful tool for achieving abstraction and ensuring consistency across unrelated classes.

#### Pros & Cons

- [+] Decoupling
- [+] Extensibility
- [+] Standardization
- [-] Slight Overhead
- [-] Complexity

```
Notes:
 - The method from the superclass takes priority over the default method in the interface. The class will inherit the superclass's method unless it explicitly overrides it.
```

<hr>

<hr>
<br>

# Access Modifier

Access modifiers prevent data members or functions of one class from tampering 🛑 with another class while restricting its access. It allows us to select which members can be accessed directly by outside functions and which are not. ✅

## Public scope

A public class, method, or variable is accessible from anywhere in the application, whether it’s within the same package or from a different package.

## Private

A private class, method, or variable is not accessible from anywhere in the application. It is only accessible within the same class and not from outside the class, whether in the same package, a child class, or a different package. It will be accessible only within the same class.

## Protected

The protected modifier allows access members within the same package and from subclasses in other packages. It offers more restricted access compared to public, but it is broader than private. By using protected, you enable controlled inheritance, allowing child classes to reuse and extend parent class functionality while keeping it hidden from unrelated classes.

## Default (Pakage-Private)

When no access modifier is specified, the default (package-private) access modifier is applied. Members with this access modifier are accessible only within the same package but not from outside it. This ensures that the functionality is available for closely related classes within the package while being hidden from other parts of the application.

Summary of Access Modifiers :
| Modifier | Class | Package | Subclass | Global |
|--------------|:-----:|:-------:|:--------:|:------:|
| `public` | ✅ | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ✅ | ❌ |
| `(default)` | ✅ | ✅ | ❌ | ❌ |
| `private` | ✅ | ❌ | ❌ | ❌ |

<hr>
<hr>
<br>

## 🧩 Class Diagram

A **Class Diagram** is a **static structure diagram** that describes the **structure of a system** by showing:

- **Classes**
- **Attributes**
- **Methods**
- **Relationships** among classes

---

### 🔹 Components of a Class

```plaintext
+---------------------+
|     ClassName       |
+---------------------+
| - attribute: Type   |
| + attribute: Type   |
+---------------------+
| + method(): Return  |
| - method(): Return  |
+---------------------+
```

- `+` Public
- `-` Private
- `#` Protected
- `~` Package-private (default)

---

## ✅ Relationships in Class Diagram

### 1. **Inheritance (is-a)**

- **Meaning**: One class **inherits** from another (Superclass → Subclass)
- **Syntax**: Solid line with a **hollow triangle** pointing to the superclass
- **Keyword**: `extends`
- **Example**: `Dog` **is-a** `Animal`

```plaintext
    Animal
      ▲
      |
     Dog
```

---

### 2. **Association (has-a)**

- **Meaning**: A class **uses or contains** another class as an attribute
- **Syntax**: Solid line between classes (optionally with multiplicity at ends)
- **Example**: `Library` **has-a** `Book`

```plaintext
Library ─────── Book
```

#### Types of Association:

| Type         | Description                                     |
| ------------ | ----------------------------------------------- |
| One-to-One   | A person has one passport                       |
| One-to-Many  | A library has many books                        |
| Many-to-Many | Students enroll in many courses, and vice versa |

---

### 3. **Aggregation (Whole-Part)**

- **Loose "has-a"** relationship
- Syntax: **Hollow diamond** at the whole (container) side
- Example: `Department` **has-a** `Professor` (professor can exist without department)

```plaintext
Department ◇────── Professor
```

---

### 4. **Composition (Strong Containment)**

- **Strong "has-a"** relationship (lifespan is tightly bound)
- Syntax: **Filled diamond** at the whole (container) side
- Example: `House` **has-a** `Room` (room cannot exist without house)

```plaintext
House ◆────── Room
```

---

### 5. **Dependency (uses-a / depends-on)**

- **Meaning**: One class **temporarily uses** another (usually as a parameter or local object)
- **Syntax**: **Dotted arrow** pointing to the depended-on class
- **Example**: `Order` uses `PaymentService`

```plaintext
Order ─ - - - - - - - - - - -▶ PaymentService
```

---

### 6. **Realization (implements)**

- **Meaning**: A class **implements** an interface (like a contract)
- **Syntax**: **Dotted line** with a **hollow triangle** pointing to the interface
- **Keyword**: `implements`
- **Example**: `Printer` implements `IPrintable`

```plaintext
  IPrintable
      △
      ⋯⋯⋯⋯
     Printer
```

---

### Summary Table

| Relationship | Meaning         | Symbol              | Lifespan Dependency |
| ------------ | --------------- | ------------------- | ------------------- |
| Inheritance  | "is-a"          | ▲ (hollow triangle) | No                  |
| Realization  | "implements"    | ▲ + dotted line     | No                  |
| Association  | "has-a"         | ─                   | No                  |
| Aggregation  | "has-a (whole)" | ◇ (hollow diamond)  | No                  |
| Composition  | "has-a (part)"  | ◆ (filled diamond)  | Yes                 |
| Dependency   | "uses-a"        | ➝ (dotted arrow)    | Temporary / None    |

---

---

<br>

# Generics

Generics provide a way to parameterize types in Java. They enable classes, interfaces, and methods to operate on various data types without the need to specify the exact type at compile time. By using generics, developers can ensure type safety, reduce code duplication, and improve readability.

## Types of Java Generics

### 1. **Generic Classes**

Generic classes allow you to define a class with type parameters, enabling it to work with different data types while maintaining type safety.

### 2. **Generic Methods**

Generic methods allow you to define a method with type parameters, enabling it to operate on different data types without the need to specify the exact type at compile time.

### 3. **Generic Interfaces**

Generic interfaces allow you to define an interface with type parameters, enabling classes that implement the interface to specify the type they will use.

## Benefits of Using Generics

- **Type Safety**: Generics provide compile-time type checking, reducing the risk of runtime errors due to type mismatches.
- **Code Reusability**: You can write a single class or method that can work with different data types, reducing code duplication.
- **Improved Readability**: Generics make
  the code more readable and self-documenting by clearly indicating the types being used.
- **Elimination of Type Casts**: Generics eliminate the need for explicit type casting, making the code cleaner and less error-prone.

## Wildcards

Wildcards in Java generics allow you to use a placeholder for an unknown type. They are useful when you want to work with a generic type but don't know the exact type at compile time.

### Types of Wildcards

- **Unbounded Wildcard (`?`)**: Represents any type. It is used when you want to allow any type to be passed.

  ```java
  public void printList(List<?> list) {
      for (Object item : list) {
          System.out.println(item);
      }
  }
  ```

- **Upper Bounded Wildcard (`? extends Type`)**: Represents a type that is a subtype of the specified type. It is used when you want to restrict the type to a specific hierarchy.

  ```java
  public void processNumbers(List<? extends Number> numbers) {
      for (Number number : numbers) {
          System.out.println(number);
      }
  }
  ```

- **Lower Bounded Wildcard (`? super Type`)**: Represents a type that is a supertype of the specified type. It is used when you want to allow a type and its supertypes.

  ```java
  public void addNumbers(List<? super Integer> list) {
      list.add(10);
      list.add(20);
  }
  ```
