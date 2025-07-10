class PaymentProcessor {
  private String paymentMethod;
  public PaymentProcessor(String paymentMethod) {
    this.paymentMethod = paymentMethod;
  }

  // Processes payment but includes logic for unsupported future payment methods
  public void processPayment(double amount) {
    if (paymentMethod.equalsIgnoreCase("CreditCard")) {
      System.out.println(
          "Processing payment of $" + amount + " via Credit Card.");
    } else if (paymentMethod.equalsIgnoreCase("DebitCard")) {
      System.out.println(
          "Processing payment of $" + amount + " via Debit Card.");
    } else if (paymentMethod.equalsIgnoreCase("PayPal")) {
      // Unnecessary feature for future use
      System.out.println("Processing payment of $" + amount + " via PayPal.");
    } else if (paymentMethod.equalsIgnoreCase("Crypto")) {
      // Unnecessary feature for future use
      System.out.println(
          "Processing payment of $" + amount + " via Cryptocurrency.");
    } else {
      System.out.println("Payment method not supported.");
    }
  }
}

public class Main {
  public static void main(String[] args) {
    // Interviewer's requirement: Only DebitCard and CreditCard payments
    PaymentProcessor processor = new PaymentProcessor("CreditCard");
    processor.processPayment(
        100); // Output: Processing payment of $100 via Credit Card.
    PaymentProcessor invalidProcessor = new PaymentProcessor("PayPal");
    invalidProcessor.processPayment(
        50); // Output: Processing payment of $50 via PayPal. (Not required!)
  }
}