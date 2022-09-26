package g55047.humbug.model;

/**
 * The Model interface contains the methods of the Game class.
 *
 * @author Marika Winska (55047)
 */
public interface Model {

    /**
     * Getter for the board.
     *
     * @return the board.
     */
    public Board getBoard();

    /**
     * Getter for the array of animals.
     *
     * @return the array of animals.
     */
    public Animal[] getAnimals();

    /**
     * Getter for the remaining moves.
     *
     * @return number of remaining moves.
     */
    public int getRemainingMoves();

    /**
     * Initializes the game board and the animals for the desired level.
     *
     * @param level the level that's going to be played.
     */
    public void startLevel(int level);

    /**
     * Getter for the level status.
     *
     * @return level status.
     */
    public LevelStatus getLevelStatus();

    /**
     * Makes the move if it is permitted.
     *
     * @param position the position where the animal wants to move.
     * @param direction the direction in which the animal wants to move.
     */
    public void move(Position position, Direction direction);

    /**
     * Checks if the position is free.
     *
     * @param position the position to be checked.
     * @return true if the position is free, false otherwise.
     */
    boolean isFree(Position position);

    /**
     * Updates the level status.
     */
    public void updateStatus();

}
