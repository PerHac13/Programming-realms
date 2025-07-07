class Test {
  // A Generic method example
  static <T> void genericDisplay(T element) {
    System.out.println(element.getClass().getName() + " = " + element);
  }

  // Driver method
  public static void main(String[] args) {
    // Calling generic method with Integer argument
    genericDisplay(11);

    // Calling generic method with String argument
    genericDisplay("CodeWithAryan");

    // Calling generic method with double argument
    genericDisplay(1.0);
  }
}
// Generic class example
class Test<T> {
  // An object of type T is declared
  T obj;
  Test(T obj) {
    this.obj = obj;
  } // constructor
  public T getObject() {
    return this.obj;
  }
}

class Main {
  public static void main(String[] args) {
    // instance of Integer type
    Test<Integer> iObj = new Test<Integer>(15);
    System.out.println(iObj.getObject());
    // instance of String type
    Test<String> sObj = new Test<String>("CodeWithAryan");
    System.out.println(sObj.getObject());
  }
}

// Generic interface example
interface GenericInterface<T> {
    void doSomething(T t);

    T getSomething();
}