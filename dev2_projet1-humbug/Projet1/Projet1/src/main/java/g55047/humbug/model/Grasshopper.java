package g55047.humbug.model;

/**
 * Represents the grasshopper that jumps to the next free square, bouncing off
 * other animals that may be in its path and jumps over the walls.
 *
 * @author Marika Winska (55047)
 */
public class Grasshopper extends Animal {

    private final String display = "G";

    /**
     * Constructor of the class Grasshopper.
     *
     * @param positionOnBoard the position at which the grasshopper is created.
     */
    public Grasshopper(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Grasshopper.
     */
    public Grasshopper() {
        super();
    }

    /**
     * Getter for the grasshopper display.
     *
     * @return display of the grasshopper.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the grasshopper on the game board in the desired direction as long
     * as it does not arrive on a free square.
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
        while (position != null && !board.isNextFree(position, direction, animals)) {
            position = moveOneJumping(board, direction, animals);
        }

        position = moveOneJumping(board, direction, animals);
        position = testOnStar(board, position);

        return position;
    }

}
