package g55047.humbug.model;

/**
 * Enumeration of directions in which the animals can move on the game board.
 *
 * @author Marika Winska (55047)
 */
public enum Direction {
    NORTH(-1, 0), SOUTH(1, 0), EAST(0, 1), WEST(0, -1);

    private final int deltaRow;
    private final int deltaColumn;

    /**
     * Constructor of the class Direction.
     *
     * @param deltaRow an animal's movement in row.
     * @param deltaColumn an animal's movement in column.
     */
    private Direction(int deltaRow, int deltaColumn) {
        this.deltaRow = deltaRow;
        this.deltaColumn = deltaColumn;
    }

    /**
     * Getter of delta row.
     *
     * @return movement in deltaRow.
     */
    public int getDeltaRow() {
        return deltaRow;
    }

    /**
     * Getter of delta column.
     *
     * @return movement in deltaColumn.
     */
    public int getDeltaColumn() {
        return deltaColumn;
    }

    /**
     * Gives the opposite direction to a direction.
     *
     * @return opposite direction.
     */
    public Direction opposite() {
        Direction direction = this;
        switch (direction) {
            case NORTH:
                direction = SOUTH;
                break;
            case SOUTH:
                direction = NORTH;
                break;
            case WEST:
                direction = EAST;
                break;
            case EAST:
                direction = WEST;
        }

        return direction;
    }

}
