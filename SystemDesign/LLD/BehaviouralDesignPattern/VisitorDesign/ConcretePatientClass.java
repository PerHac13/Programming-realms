package SystemDesign.LLD.BehaviouralDesignPattern.VisitorDesign;

public class ConcretePatientClass {

}
class ChildPatient implements Patient {
  @Override
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}

class AdultPatient implements Patient {
  @Override
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}

class SeniorPatient implements Patient {
  @Override
  public void accept(Visitor visitor) {
    visitor.visit(this);
  }
}