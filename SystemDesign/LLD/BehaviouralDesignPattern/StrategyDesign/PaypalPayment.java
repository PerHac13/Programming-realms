package SystemDesign.LLD.BehaviouralDesignPattern.StrategyDesign;

public class PaypalPayment implements PaymentStrategy {
    public void processPayment() {
    System.out.println("Processing credit card payment...");
  }
}