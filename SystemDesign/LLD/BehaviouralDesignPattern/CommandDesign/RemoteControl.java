public class RemoteControl {
  // Invoker class that holds commands
  // and can execute them
  private Command onCommand;
  private Command offCommand;
  public void setOnCommand(Command onCommand) {
    this.onCommand = onCommand;
  }
  public void setOffCommand(Command offCommand) {
    this.offCommand = offCommand;
  }
  public void pressOnButton() {
    onCommand.execute();
  }
  public void pressOffButton() {
    offCommand.execute();
  }
}
