# Memento Design Pattern

```
The Memento Design Pattern is like having a personal memory bank for your objects—storing snapshots of their state so you can always roll back when needed. By separating state saving from your core logic, you keep your code clean, modular, and easy to maintain. Whether it’s for undo functionality in a text editor, saving game progress, or managing complex configurations, the Memento Pattern is an incredibly powerful tool in your design pattern toolkit.
```

The Memento Design Pattern is a behavioral design pattern that allows an object to capture its internal state without exposing its implementation details. This pattern is useful for implementing undo/redo functionality, saving and restoring the state of an object, or implementing checkpoints in a system.

### Key Components

- **Memento**: The object that stores the state of another object.
- **Originator**: The object whose state needs to be saved and restored.
- **Caretaker**: The object that manages the mementos and is responsible for saving and restoring the state of the originator.

### Pros and Cons

- [+] Encapsulates state
- [+] Supports undo/redo functionality
- [+] Separation of concerns

---

### Real world Use Cases

- Text editors
- Game States Saving
- Form Data Recovery
- Configuration Management
- Financial Transactions
