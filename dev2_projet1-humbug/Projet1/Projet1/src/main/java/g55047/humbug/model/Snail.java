package g55047.humbug.model;

/**
 * Represents the snail that moves one square in the given direction (if there
 * are no obstacles (a wall or an other animal).
 *
 * @author Marika Winska (55047)
 */
public class Snail extends Animal {

    private final String display = "@";

    /**
     * Constructor of the class Snail.
     *
     * @param positionOnBoard the position at which the snail is created.
     */
    public Snail(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Snail.
     */
    public Snail() {
        super();
    }

    /**
     * Getter for the snail display.
     *
     * @return display of the snail.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the snail on the game board in the desired direction if the square
     * is available and if there is no wall that is blocking.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    @Override
    public Position move(Board board, Direction direction, Animal... animals) {
        Position position = moveOneCrawling(board, direction, animals);
        position = testOnStar(board, position);
        return position;
    }

}
