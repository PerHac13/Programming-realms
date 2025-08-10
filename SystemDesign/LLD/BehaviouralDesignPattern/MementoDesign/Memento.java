package SystemDesign.LLD.BehaviouralDesignPattern.MementoDesign;

class Memento {
  private final String text;
  public Memento(String text) {
    this.text = text;
  }

  public String getText() {
    return text;
  }
}