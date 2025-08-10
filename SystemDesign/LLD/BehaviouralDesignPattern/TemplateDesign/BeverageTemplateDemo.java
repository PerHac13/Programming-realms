package SystemDesign.LLD.BehaviouralDesignPattern.TemplateDesign;

abstract class Beverage {
  // The template method - makes sure the algorithm steps are followed
  final void prepareRecipe() {
    boilWater();
    brew();
    pourInCup();
    addCondiments();
  }
  // Common methods
  void boilWater() {
    System.out.println("Boiling water...");
  }
  void pourInCup() {
    System.out.println("Pouring into cup...");
  }
  // Steps to be customized by subclasses
  abstract void brew();
  abstract void addCondiments();
}

// Concrete implementation for Coffee
class CoffeeBeverage extends Beverage {
  @Override
  void brew() {
    System.out.println("Brewing coffee...");
  }
  @Override
  void addCondiments() {
    System.out.println("Adding sugar and milk...");
  }
}

// Concrete implementation for Tea
class TeaBeverage extends Beverage {
  @Override
  void brew() {
    System.out.println("Steeping tea bag...");
  }
  @Override
  void addCondiments() {
    System.out.println("Adding lemon...");
  }
}

public class BeverageTemplateDemo {
  public static void main(String[] args) {
    Beverage coffee = new CoffeeBeverage();
    Beverage tea = new TeaBeverage();
    System.out.println("Making coffee...");
    coffee.prepareRecipe();
    System.out.println("nMaking tea...");
    tea.prepareRecipe();
  }
}