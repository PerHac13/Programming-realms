package SystemDesign.LLD.BehaviouralDesignPattern.MementoDesign;

public class MementoPatternDemo {
  public static void main(String[] args) {
    TextEditor editor = new TextEditor();
    EditorHistory history = new EditorHistory();
    // Initial state
    editor.setText("Hello");
    history.saveState(editor.save());
    // First change
    editor.setText("Hello, World!");
    history.saveState(editor.save());
    // Second change
    editor.setText("Hello, World! Welcome!");
    System.out.println("Current: " + editor.getText());
    // Undo the last change
    Memento previousState = history.undo(editor.save());
    if (previousState != null) {
      editor.restore(previousState);
      System.out.println("After undo: " + editor.getText());
    }
    // Redo the undone change
    Memento redoState = history.redo(editor.save());
    if (redoState != null) {
      editor.restore(redoState);
      System.out.println("After redo: " + editor.getText());
    }
  }
}
