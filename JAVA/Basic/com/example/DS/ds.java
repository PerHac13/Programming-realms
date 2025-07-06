import java.util.*;

class DS{

    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();

        list.add("Java");
        list.add("Python");
        list.add("C++");
        list.add("JavaScript");

        // Set HashSet
        HashSet<String> set = new HashSet<String>();

        // Map
        Map<String, Integer> map = new HashMap<String, Integer>();
        map.put("Java", 1);
        map.put("Python", 2);


        System.out.println("List of programming languages:", list);

    }
}