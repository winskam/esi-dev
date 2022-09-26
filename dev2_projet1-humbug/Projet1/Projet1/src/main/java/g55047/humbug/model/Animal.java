package g55047.humbug.model;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonSubTypes.Type;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import com.fasterxml.jackson.annotation.JsonTypeInfo.Id;

/**
 * Abstract class Animal which will contain subclasses.
 *
 * @author Marika Winska (55047)
 */
@JsonTypeInfo(use = Id.NAME,
        include = JsonTypeInfo.As.PROPERTY,
        property = "type")
@JsonSubTypes({
    @Type(value = Bumbelbee.class),
    @Type(value = Grasshopper.class),
    @Type(value = Ladybird.class),
    @Type(value = Snail.class),
    @Type(value = Spider.class),
    @Type(value = Butterfly.class)})
public abstract class Animal {

    private Position positionOnBoard;
    private boolean onStar = false;
    private String display;

    /**
     * Constructor of the class Animal.
     *
     * @param positionOnBoard animal's position on the game board at
     * initialization.
     */
    public Animal(Position positionOnBoard) {
        this.positionOnBoard = positionOnBoard;
    }

    /**
     * Constructor of the class Animal.
     */
    public Animal() {
        this.positionOnBoard = new Position();
    }

    /**
     * Getter for animal-specific display.
     *
     * @return corresponding display.
     */
    public String getDisplay() {
        return display;
    }

    /**
     * Getter of positionOnBoard.
     *
     * @return the animal's position on board.
     */
    public Position getPositionOnBoard() {
        return positionOnBoard;
    }

    /**
     * Setter of positionOnBoard.
     *
     * @param positionOnBoard the new animal's position.
     */
    public void setPositionOnBoard(Position positionOnBoard) {
        this.positionOnBoard = positionOnBoard;
    }

    /**
     * Getter of onStar who checks if the animal is on a star square.
     *
     * @return true if the animal is on a star square, false otherwise.
     */
    public boolean isOnStar() {
        return onStar;
    }

    /**
     * Setter of onStar that sets true or false.
     *
     * @param onStar true or false.
     */
    void setOnStar(boolean onStar) {
        this.onStar = onStar;
    }

    /**
     * Test if the animal is on a star square.
     *
     * @param board the game board.
     * @param position the current position of the animal on the game board.
     * @return the position changed to onStar, or not.
     */
    Position testOnStar(Board board, Position position) {
        position = getPositionOnBoard();
        if (position != null) {
            position = setGrass(board, position);
        }

        return position;
    }

    /**
     * Change the star square into a grass square.
     *
     * @param board the game board.
     * @param position the current position of the animal on the game board.
     * @return the position with a new type of square.
     */
    Position setGrass(Board board, Position position) {
        if (board.getSquareType(position) == SquareType.STAR) {
            this.setOnStar(true);
            board.setSquareGrass(position);
        }

        return position;
    }

    /**
     * Moves the animal one square on the game board in the desired direction if
     * the square is available and if there is no wall that is blocking.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    Position moveOneCrawling(Board board, Direction direction, Animal... animals) {
        Position position = this.getPositionOnBoard();
        if (board.isNextFree(position, direction, animals)
                && !board.isWall(position, direction)
                && !board.isNextWall(position, direction)) {
            if (board.isInside(position.next(direction))) {
                position = position.next(direction);

            } else {
                position = null;
            }
        }

        this.setPositionOnBoard(position);
        return position;
    }

    /**
     * Moves the animal one square on the game board in the desired direction.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    Position moveOneJumping(Board board, Direction direction, Animal... animals) {
        Position position = this.getPositionOnBoard();
        if (board.isInside(position.next(direction))) {
            position = position.next(direction);
        } else {
            position = null;
        }

        this.setPositionOnBoard(position);
        return position;
    }

    /**
     * Moves the animal one square on the game board in the desired direction.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    Position moveOneFlying(Board board, Direction direction, Animal... animals) {
        Position position = getPositionOnBoard();
        position = position.next(direction);
        this.setPositionOnBoard(position);
        return position;
    }

    /**
     * Moves the animal over the others animals if the cases are not free.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    Position multipleFlights(Board board, Direction direction, Animal... animals) {
        Position position = getPositionOnBoard();
        boolean free = false;
        do {
            if (board.isNextFree(position, direction, animals)) {
                free = true;
            }
            position = moveOneFlying(board, direction, animals);
        } while (!free);

        if (!board.isInside(position)) {
            position = null;
        }

        return position;
    }

    /**
     * Abstract function that moves the animal, changes the position.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving, if it is
     * able to do so.
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    public abstract Position move(Board board, Direction direction, Animal... animals);

}
