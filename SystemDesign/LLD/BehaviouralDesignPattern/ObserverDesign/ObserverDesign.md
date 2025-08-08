# Observer Design Pattern

```
 the Observer Pattern allows one object (the subject) to notify other objects (the observers) whenever there is a change in its state. This is great for systems where certain parts of your application need to stay updated in real-time but shouldn’t be tightly coupled to each other.
```

### Problem Statement

- **Channel**: is the subject that notifies its subscribers (observers) about new content.
- **Subscriber**: is the observer that gets notified when new content is available.

### Problem without Observer Design Pattern

- [-] Manual Checking
- [-] Not Scalable
- [-] Hard to Extend

### Implementation of Observer Design Pattern:

- Observer Interface
- Concrete Observer Classes
- Subject Interface
- Concrete Subject Classes

### Pros and Cons

- [+] Decoupled Components
- [+] Scalable
- [+] Flexibity
- [+] Maintainability

---

### Real-World Example

- Social Media Platform
  - **Channel**: Represents a user or a group that posts content.
  - **Subscriber**: Represents users who follow the channel to receive updates.
- Stock Market
  - **Channel**: Represents a stock that provides updates on its price.
  - **Subscriber**: Represents investors who want to be notified about price changes.
- Message Notification System
  - **Channel**: Represents a messaging service that sends notifications.
  - **Subscriber**: Represents users who receive those notifications.
