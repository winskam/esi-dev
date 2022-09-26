package g55047.humbug.model;

/**
 * Represents the butterfly that moves three squares in the given direction (if
 * the square is free, otherwise the butterfly flies until it has a free
 * square).
 *
 * @author Marika Winska (55047)
 */
public class Butterfly extends Animal {

    private final String display = "Y";

    /**
     * Constructor of the class Butterfly.
     *
     * @param positionOnBoard the position at which the butterfly is created.
     */
    public Butterfly(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Butterfly.
     */
    public Butterfly() {
        super();
    }

    /**
     * Getter for the butterfly display.
     *
     * @return display of the butterfly.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the butterfly on the game board in the desired direction three
     * squares, or more if the square is not free.
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
        boolean free = true;
        for (int moves = 3; moves > 0; moves--) {
            position = moveOneFlying(board, direction, animals);
            if (moves == 2 && !board.isNextFree(position, direction, animals)) {
                free = false;
            }
        }
        if (board.isInside(position)) {
            if (!free) {
                position = multipleFlights(board, direction, animals);
            }
        } else {
            position = null;
        }

        this.setPositionOnBoard(position);
        position = testOnStar(board, position);

        return position;
    }

}
