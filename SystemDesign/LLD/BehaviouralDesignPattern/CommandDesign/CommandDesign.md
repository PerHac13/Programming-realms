# Command Design Pattern

```
The Command Design Pattern helps you decouple the request (action) from the object that performs it. This pattern allows for extensible, maintainable, and scalable solutions by encapsulating requests into objects and executing them on demand. By applying this pattern, you can write more clean, flexible, and robust code.
```

The Command Design Pattern is one of the behavioral design patterns in software development. At its core, it’s about encapsulating a request as an object, which allows you to parameterize objects with operations, delay execution, and queue requests. The idea is that commands (actions you want to perform) are wrapped as objects, and these command objects can then be passed around, stored, or executed when needed. It's kind of like giving someone a "to-do" list where each item represents an action to be performed.

## Components of Command Design Pattern

1. **Command**: This is an interface or abstract class that declares a method for executing a command.
2. **ConcreteCommand**: This class implements the Command interface and defines the binding between a receiver and an action. It invokes the corresponding operation on the receiver.
3. **Receiver**: This is the object that knows how to perform the operations associated with the command. It contains the business logic.
4. **Invoker**: This class is responsible for initiating the command. It holds a reference to the command and can execute it. The invoker does not know the details of how the command is executed.
5. **Client**: This is the part of the application that creates a command and associates it with a receiver. The client can also set the command on the invoker.

### Pros and Cons

- [+] No Modification of existing code
- [+] Seperation of concerns
- [+] Flexibility in adding new commands

---

### Real-World Example

- Undo/Redo Operations
- GUI Buttons
- Task Scheduling
