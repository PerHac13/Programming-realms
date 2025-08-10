package SystemDesign.LLD.BehaviouralDesignPattern.TemplateDesign;
abstract class BeverageWithHook {
  // The template method with a hook
  final void prepareRecipe() {
    boilWater();
    brew();
    pourInCup();
    // Only add condiments if the customer wants them
    if (customerWantsCondiments()) {
      addCondiments();
    }
  }
  void boilWater() {
    System.out.println("Boiling water...");
  }
  void pourInCup() {
    System.out.println("Pouring into cup...");
  }
  abstract void brew();
  abstract void addCondiments();
  // Hook method with default behavior
  boolean customerWantsCondiments() {
    return true;
  }
}

class CustomCoffee extends BeverageWithHook {
  @Override
  void brew() {
    System.out.println("Brewing coffee...");
  }
  @Override
  void addCondiments() {
    System.out.println("Adding sugar and milk...");
  }
  // Suppose this customer doesn't want condiments
  @Override
  boolean customerWantsCondiments() {
    return false;
  }
}
public class BeverageWithHookDemo {
  public static void main(String[] args) {
    BeverageWithHook coffee = new CustomCoffee();
    System.out.println("Making custom coffee...");
    coffee.prepareRecipe();
  }
}