# Chain of Command Design Pattern

The Chain of Command Design Pattern is a behavioral design pattern that allows an object to pass a request along a chain of potential handlers until one of them handles the request. This pattern is useful for decoupling the sender of a request from its receivers, allowing for more flexible and dynamic handling of requests.

```
The Chain of Responsibility design pattern is like passing a baton in a relay race—each handler gets its turn until the request is processed. By using this pattern, you avoid a tangled web of if-else statements, resulting in cleaner, modular, and extendable code.
```

### Key Components

- **Handler**: An interface or abstract class defining a method for handling requests and a reference to the next handler in the chain.
- **Concrete Handlers**: Classes that implement the Handler interface and handle specific requests. They can either process the request or pass it to the next handler in the chain.
- **Client**: The object that initiates the request and starts the chain of handlers.

### Pros and Cons

- [+] Loose Coupling between sender and handler
- [+] Enhanced Flexibility and Scalability
- [+] Improved Code Organization & Maintainability
- [+] Reusability of Handlers
- [+] Dynamic Request Handling
- [-] Complexity in Handler Management
- [-] Potential Performance Overhead

---

### Real-World Example

- Technical Support
- Logging System
- GUI Event Handling
- Authentication and Authorization
