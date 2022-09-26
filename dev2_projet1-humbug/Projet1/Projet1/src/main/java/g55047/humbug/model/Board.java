package g55047.humbug.model;

/**
 * A class that creates a new game board.
 *
 * @author Marika Winska (55047)
 */
public class Board {

    private final Square[][] squares;

    /**
     * Constructor of board.
     *
     * @param squares squares on which an animal can move.
     */
    Board(Square[][] squares) {
        this.squares = squares;
    }

    /**
     * Constructor of the class Board.
     */
    public Board() {
        this.squares = null;
    }

    /**
     * Getter of squares.
     *
     * @return squares.
     */
    public Square[][] getSquares() {
        return squares;
    }

    /**
     * Checks if the position is on an existing square or not.
     *
     * @param position An animal's position.
     * @return true if the position is on a square, false otherwise.
     */
    public boolean isInside(Position position) {
        if (position.getRow() < 0 || position.getColumn() < 0
                || position.getRow() >= getNbRow() || position.getColumn() >= getNbColumn()) {
            return false;
        }

        return squares[position.getRow()][position.getColumn()] != null;
    }

    /**
     * Checks the type of a square at a given position.
     *
     * @param position An animal's position.
     * @return the type.
     */
    public SquareType getSquareType(Position position) {
        if (!isInside(position)) {
            throw new IllegalArgumentException("No square in this position.");
        }

        return squares[position.getRow()][position.getColumn()].getType();
    }

    /**
     * @return the number of row on the game board.
     */
    public int getNbRow() {
        return squares.length;
    }

    /**
     * @return the number of column on the game board.
     */
    public int getNbColumn() {
        return squares[0].length;
    }

    /**
     * Setter that changes a square to grass.
     *
     * @param position square position to be changed.
     */
    public void setSquareGrass(Position position) {
        this.squares[position.getRow()][position.getColumn()] = new Square(SquareType.GRASS);
    }

    /**
     * Checks if the next square in the desired direction is available.
     *
     * @param position the current position of the animal on the game board.
     * @param direction the direction in which the animal is moving.
     * @param animals an array of animals on the game board.
     * @return true if the square next to it is available, false otherwise.
     */
    boolean isNextFree(Position position, Direction direction, Animal... animals) {
        boolean free = true;
        for (Animal animal : animals) {
            if (!animal.isOnStar() && animal.getPositionOnBoard().equals(position.next(direction))) {
                free = false;
            }
        }

        return free;
    }

    /**
     * Checks if the square at a given position has a wall in the given
     * direction.
     *
     * @param position the position to be checked.
     * @param direction the direction in which to check.
     * @return true if there is a wall, false otherwise.
     */
    public boolean isWall(Position position, Direction direction) {
        return squares[position.getRow()][position.getColumn()].hasWall(direction);
    }

    /**
     * Checks if there is a wall opposite the square in the given direction.
     *
     * @param position the current position.
     * @param direction the direction in which to check.
     * @return true if there is an opposite wall, false otherwise.
     */
    boolean isNextWall(Position position, Direction direction) {
        Position nextPos = position.next(direction);
        return isInside(nextPos) && squares[nextPos.getRow()][nextPos.getColumn()].hasWall(direction.opposite());
    }

    /**
     * Initializes the game board of the first level.
     *
     * @return the board.
     */
    public static Board getInitialBoard() {
        Square[][] squares = {{new Square(SquareType.GRASS), new Square(SquareType.GRASS), null},
        {null, new Square(SquareType.GRASS), new Square(SquareType.GRASS)},
        {null, null, new Square(SquareType.STAR)}};

        return new Board(squares);
    }

}
