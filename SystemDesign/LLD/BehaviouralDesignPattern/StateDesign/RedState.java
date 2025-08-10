package SystemDesign.LLD.BehaviouralDesignPattern.StateDesign;

class RedState implements TrafficLightState {
  @Override
  public void next(TrafficLightContext context) {
    System.out.println("Switching from RED to GREEN. Cars go!");
    context.setState(new GreenState());
  }
  @Override
  public String getColor() {
    return "RED";
  }
}

// Concrete State: Green
class GreenState implements TrafficLightState {
  @Override
  public void next(TrafficLightContext context) {
    System.out.println("Switching from GREEN to YELLOW. Slow down!");
    context.setState(new YellowState());
  }
  @Override
  public String getColor() {
    return "GREEN";
  }
}

// Concrete State: Yellow
class YellowState implements TrafficLightState {
  @Override
  public void next(TrafficLightContext context) {
    System.out.println("Switching from YELLOW to RED. Stop!");
    context.setState(new RedState());
  }
  @Override
  public String getColor() {
    return "YELLOW";
  }
}