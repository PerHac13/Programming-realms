package SystemDesign.Problem.TictacToe;

// State Pattern
public interface IGameState {
    void next(GameContext context, Player player, boolean hasWon);
    boolean isGameOver();
}

