/* *****************************************************************************
 *  Name:              Shaikh Abdullah
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

/** Represents a random word picker */
public class RandomWord {

  /**
   * @param args sequence of words
   */
  public static void main(String[] args) {
    int index = 0;
    String champion = "";

    while (!StdIn.isEmpty()) {
      String word = StdIn.readString();
      boolean accept = StdRandom.bernoulli(1 / (index + 1.0));
      if (accept) {
        champion = word;
      }
      index++;
    }
    StdOut.println(champion);
  }
}
