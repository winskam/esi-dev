package g55047.humbug.model;

/**
 * Represents the ladybird that moves two squares in the given direction and
 * stops before if there is an obstacle (a wall or an other animal).
 *
 * @author Marika Winska (55047)
 */
public class Ladybird extends Animal {

    private final String display = "Ö";

    /**
     * Constructor of the class Ladybird.
     *
     * @param positionOnBoard the position at which the ladybird is created.
     */
    public Ladybird(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Ladybird.
     */
    public Ladybird() {
        super();
    }

    /**
     * Getter for the ladybird display.
     *
     * @return display of the ladybird.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the ladybird on the game board in the desired direction if the
     * square is available and if there is no wall that is blocking.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    @Override
    public Position move(Board board, Direction direction, Animal... animals) {
        Position position = getPositionOnBoard();
        for (int moves = 2; moves > 0; moves--) {
            position = moveOneCrawling(board, direction, animals);
            if (position == null) {
                moves = 0;
            }
        }
        position = testOnStar(board, position);

        return position;
    }

}
