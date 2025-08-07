package SystemDesign.LLD.BehaviouralDesignPattern.StrategyDesign;

public class CreditCardPayment implements PaymentStrategy {
    public void processPayment() {
    System.out.println("Processing credit card payment...");
  }
}
