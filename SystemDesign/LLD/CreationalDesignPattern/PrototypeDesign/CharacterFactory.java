package SystemDesign.LLD.CreationalDesignPattern.PrototypeDesign;

public class CharacterFactory {
    private final Character prototypeCharacter;

  public CharacterFactory() {
    prototypeCharacter = new Character("DefaultName", 100, 50, 1);
  }

  public Character createCharacterWithNewName(String name) throws CloneNotSupportedException {
    Character cloned = prototypeCharacter.clone();
    cloned.setName(name);
    return cloned;
  }

  public Character createCharacterWithNewLevel(int level) throws CloneNotSupportedException {
    Character cloned = prototypeCharacter.clone();
    cloned.setLevel(level);
    return cloned;
  }

  public Character createCharacterWithNewAttackPower(int attackPower) throws CloneNotSupportedException {
    Character cloned = prototypeCharacter.clone();
    cloned.setAttackPower(attackPower);
    return cloned;
  }
}
