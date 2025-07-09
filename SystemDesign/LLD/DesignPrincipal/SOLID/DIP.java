interface NotificationService {
  void sendNotification(String message);
}

interface LoggingService {
  void logMessage(String message);
  void logError(String error);
}

interface InventoryService {
  void updateStock(Order order);
  boolean checkAvailability(Product product);
}

class EmailNotifier implements NotificationService {
  @Override
  public void sendNotification(String message) {
    // Email specific implementation
  }
}

class SMSNotifier implements NotificationService {
  @Override
  public void sendNotification(String message) {
    // SMS specific implementation
  }
}

class PushNotifier implements NotificationService {
  @Override
  public void sendNotification(String message) {
    // Push notification specific implementation
  }
}

class WarehouseInventoryService implements InventoryService {
  @Override
  public void updateStock(Order order) {
    // Update stock in warehouse
  }
  @Override
  public boolean checkAvailability(Product product) {
    // Check product availability in warehouse
    return true; // Placeholder
  }
}

class DatabaseLogger implements LoggingService {
  @Override
  public void logMessage(String message) {
    // Database logging implementation
  }
  @Override
  public void logError(String error) {
    // Error logging implementation
  }
}

class OrderService {
  private final NotificationService notificationService;
  private final LoggingService loggingService;
  private final InventoryService inventoryService;
  // Constructor injection of dependencies
  public OrderService(NotificationService notificationService,
      LoggingService loggingService, InventoryService inventoryService) {
    this.notificationService = notificationService;
    this.loggingService = loggingService;
    this.inventoryService = inventoryService;
  }

  public void placeOrder(Order order) {
    try {
      // Check inventory
      if (inventoryService.checkAvailability(order.getProduct())) {
        // Process order
        inventoryService.updateStock(order);
        // Send notification
        notificationService.sendNotification(
            "Order #" + order.getId() + " placed successfully");
        // Log success
        loggingService.logMessage(
            "Order processed successfully: " + order.getId());
      }
    } catch (Exception e) {
      loggingService.logError(
          "Error processing order: " + order.getId() + " - " + e.getMessage());
      throw e;
    }
  }
}

// Usage with dependency injection
NotificationService emailNotifier = new EmailNotifier();
LoggingService logger = new DatabaseLogger();
InventoryService inventory = new WarehouseInventoryService();
OrderService orderService = new OrderService(emailNotifier, logger, inventory);

// class EmailNotifier {
//   public void sendEmail(String message) {
//     // Configure SMTP
//     // Set up email templates
//     // Send email implementation
//   }
// }

// class OrderService {
//   private EmailNotifier emailNotifier;
//   private DatabaseLogger logger;
//   private InventorySystem inventory;
//   public OrderService() {
//     // Direct dependencies on concrete implementations
//     this.emailNotifier = new EmailNotifier();
//     this.logger = new DatabaseLogger();
//     this.inventory = new InventorySystem();
//   }
//   public void placeOrder(Order order) {
//     // Process order
//     inventory.updateStock(order);
//     emailNotifier.sendEmail("Order #" + order.getId() + " placed successfully");
//     logger.logTransaction("Order placed: " + order.getId());
//   }
// }