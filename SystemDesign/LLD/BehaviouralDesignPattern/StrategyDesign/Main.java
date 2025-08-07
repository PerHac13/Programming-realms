package SystemDesign.LLD.BehaviouralDesignPattern.StrategyDesign;

public class Main {
     public static void main(String[] args) {
    // Create strategy instances for each payment type
    PaymentStrategy creditCard = new CreditCardPayment();
    PaymentStrategy payPal = new PaypalPayment();
    // Use the Strategy Pattern to process payments
    PaymentProcessor processor =
        new PaymentProcessor(creditCard); // Initially using CreditCardPayment
    processor.processPayment(); // Processing credit card payment...
    // Dynamically change the payment strategy to PayPal
    processor.setPaymentStrategy(payPal);
    processor.processPayment(); // Processing PayPal payment...
    // You can switch back to credit card if needed
    processor.setPaymentStrategy(creditCard);
    processor.processPayment(); // Processing credit card payment...
  }
}
