package SystemDesign.Problem.TictacToe;

public class Player {
    Symbol symbol;
    IPlayerStrategy playerStategy;

    public Player(Symbol symbol, IPlayerStrategy playerStategy) {
        this.symbol = symbol;
        this.playerStategy = playerStategy;
    }

    public Symbol getSymbol() {
        return symbol;
    }

    public IPlayerStrategy getPlayerStrategy() {
        return playerStategy;
    }
}
