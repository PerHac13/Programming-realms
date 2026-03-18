package SystemDesign.Problem.TictacToe;

import java.util.Scanner;

public class HumanPlayerStrategy implements IPlayerStrategy {

    private Scanner scanner;
    private String playerName;

    public HumanPlayerStrategy(String playerName) {
        this.scanner = new Scanner(System.in);
        this.playerName = playerName;
    }

    @Override
    public Position makeMove(Board board) {
        System.out.println(playerName + ", enter your move (row and column): ");
        try {

            int row = scanner.nextInt();
            int col = scanner.nextInt();
            Position move = new Position(row, col);
            
            if(board.isValidMove(move)) {
                return move;
            } else {
            System.out.println("Invalid move. Try again.");
            return makeMove(board);
        }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter two integers.");
            scanner.nextLine(); // Clear the invalid input
            return makeMove(board);
        }
    }
    
}
