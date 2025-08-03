package SystemDesign.LLD.CreationalDesignPattern.PrototypeDesign;



public class Prototype {
    public static void main(String[] args) throws CloneNotSupportedException {
    CharacterFactory factory = new CharacterFactory();

    Character warrior = factory.createCharacterWithNewName("Warrior");
    Character mage = factory.createCharacterWithNewAttackPower(120);
    Character archer = factory.createCharacterWithNewLevel(5);

    warrior.showCharacterInfo();
    mage.showCharacterInfo();
    archer.showCharacterInfo();
  }
}
