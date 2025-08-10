package SystemDesign.LLD.BehaviouralDesignPattern.MementoDesign;

// Originator class that creates and restores mementos
class TextEditor {
  private String text;
  public void setText(String text) {
    this.text = text;
  }

  public String getText() {
    return text;
  }

  // Creates a memento (snapshot) of the current state
  public Memento save() {
    return new Memento(text);
  }

  // Restores the state from the given memento
  public void restore(Memento memento) {
    this.text = memento.getText();
  }
}

