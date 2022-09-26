package g55047.humbug.model;

import java.util.Objects;

/**
 * Position on the board. A position consists of a row and a column.
 *
 * @author Marika Winska (55047)
 */
public class Position {

    private final int row;
    private final int column;

    /**
     * Constructor of Position on board.
     *
     * @param row the position on the row.
     * @param column the position on the column.
     */
    public Position(int row, int column) {
        this.row = row;
        this.column = column;
    }

    /**
     * Constructor of Position.
     */
    public Position() {
        this.row = 0;
        this.column = 0;
    }

    /**
     * Getter of row.
     *
     * @return the position on the row.
     */
    public int getRow() {
        return row;
    }

    /**
     * Getter of column.
     *
     * @return the position on the column.
     */
    public int getColumn() {
        return column;
    }

    /**
     * Hashes an object.
     *
     * @return a hash code value for the object.
     */
    @Override
    public int hashCode() {
        return Objects.hash(row, column);
    }

    /**
     * @return a string representation of the object.
     */
    @Override
    public String toString() {
        return "(" + row + "," + column + ')';
    }

    /**
     * Checks if both objects are equal.
     *
     * @param obj the reference object with which to compare.
     * @return true if this object is the same as the obj, false otherwise.
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }

        final Position other = (Position) obj;

        return row == other.row && column == other.column;
    }

    /**
     * Calculates the new position.
     *
     * @param direction the direction in which the animal is moving.
     * @return the animal's new poition.
     */
    public Position next(Direction direction) {
        int newRow = direction.getDeltaRow() + row;
        int newColumn = direction.getDeltaColumn() + column;

        return new Position(newRow, newColumn);
    }

}
