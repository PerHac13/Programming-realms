package SystemDesign.Problem.TictacToe;

public class GameContext {
    private IGameState currentState;

    public GameContext() {
        this.currentState = new XTurnState();
    }

    public void setState(IGameState state){
        this.currentState = state;
    }

    public void next(Player player, boolean hasWon){
        currentState.next(this, player, hasWon);
    }

    public boolean isGameOver(){
        return currentState.isGameOver();
    }

    public IGameState getCurrentState() {
        return currentState;
    }
}
