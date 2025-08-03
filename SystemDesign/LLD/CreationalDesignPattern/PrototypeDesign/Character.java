package SystemDesign.LLD.CreationalDesignPattern.PrototypeDesign;

public class Character implements Cloneable {
    private String name;
  private int health;
  private int attackPower;
  private int level;

  public Character(String name, int health, int attackPower, int level) {
    this.name = name;
    this.health = health;
    this.attackPower = attackPower;
    this.level = level;
  }

  // Standard clone method
  @Override
  public Character clone() throws CloneNotSupportedException {
    return (Character) super.clone(); // Shallow copy
  }

  public void showCharacterInfo() {
    System.out.println("Character [Name=" + name + ", Health=" + health
        + ", AttackPower=" + attackPower + ", Level=" + level + "]");
  }

  // Setters to allow modification after cloning
  public void setName(String name) {
    this.name = name;
  }

  public void setLevel(int level) {
    this.level = level;
  }

  public void setAttackPower(int attackPower) {
    this.attackPower = attackPower;
  }
}
