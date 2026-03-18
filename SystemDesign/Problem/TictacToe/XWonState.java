package SystemDesign.Problem.TictacToe;

public class XWonState implements IGameState {
    @Override
    public void next(GameContext context, Player player, boolean hasWon) {
        // Game is already won, no further state transitions
    }

    @Override
    public boolean isGameOver() {
        return true;
    }
    
}
