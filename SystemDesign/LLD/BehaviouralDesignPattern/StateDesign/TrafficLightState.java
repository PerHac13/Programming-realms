package SystemDesign.LLD.BehaviouralDesignPattern.StateDesign;

// State interface for the Traffic Light State Design Pattern
public interface TrafficLightState {
    void next(TrafficLightContext context);
    String getColor();
}
