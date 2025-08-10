package SystemDesign.LLD.BehaviouralDesignPattern.ChainOfCommandDesign;

public class ConcreteHandlers {

}
class Supervisor extends Approver {
  @Override
  public void processLeaveRequest(int leaveDays) {
    if (leaveDays <= 3) {
      System.out.println("Supervisor approved the leave.");
    } else if (nextApprover != null) {
      nextApprover.processLeaveRequest(leaveDays);
    }
  }
}

class Manager extends Approver {
  @Override
  public void processLeaveRequest(int leaveDays) {
    if (leaveDays <= 7) {
      System.out.println("Manager approved the leave.");
    } else if (nextApprover != null) {
      nextApprover.processLeaveRequest(leaveDays);
    }
  }
}

class Director extends Approver {
  @Override
  public void processLeaveRequest(int leaveDays) {
    if (leaveDays <= 14) {
      System.out.println("Director approved the leave.");
    } else if (nextApprover != null) { // Pass on if not handled
      nextApprover.processLeaveRequest(leaveDays);
    } else {
      System.out.println("Leave request denied. Too many days!");
    }
  }
}

class HR extends Approver {
    @Override
    public void processLeaveRequest(int leaveDays) {
        System.out.println("HR: Leave request requires further discussion.");
    }
}