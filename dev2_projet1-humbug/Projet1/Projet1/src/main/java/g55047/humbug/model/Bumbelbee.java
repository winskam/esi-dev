package g55047.humbug.model;

/**
 * Represents the bumbelbee that moves two squares in the given direction (if
 * the square is free, otherwise the bumblebee flies until it has a free square.
 *
 * @author Marika Winska (55047)
 */
public class Bumbelbee extends Animal {

    private final String display = "B";

    /**
     * Constructor of the class Bumbelbee.
     *
     * @param positionOnBoard the position at which the bumbelbee is created.
     */
    public Bumbelbee(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Bumbelbee.
     */
    public Bumbelbee() {
        super();
    }

    /**
     * Getter for the bumbelbee display.
     *
     * @return display of the bumbelbee.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the bumbelbee on the game board in the desired direction two
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
        for (int moves = 2; moves > 0; moves--) {
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
