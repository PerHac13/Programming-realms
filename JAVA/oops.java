import com.example.demo.A;
import com.example.threads.ThreadExample;

class Keyboard {
    private int keys;
    String color;
    public void pressed() {
        System.out.println("Key pressed");
        // x is a keyword in Java, not a parameter name
    }
    public void setKey(int keys){
        this.keys=keys;
    }

}

class AdvancedKeyboard extends Keyboard {
    public void pressed() {
        System.out.println("Advanced key pressed");
        // x is a keyword in Java, not a parameter name
    }

}

class OOPS {
    public static void main(String args[]) {
        System.out.println("Hello, World!");

        int num;
        num=8;

        Keyboard k = new Keyboard();

        k.pressed();
        k.setKey(104);
        
        k.color = "Black";
        System.out.println("Color: " + k.color);
        A.main(args);
        ThreadExample.main(args);


        // int num[] = {1, 2, 3, 4, 5};
    }
}