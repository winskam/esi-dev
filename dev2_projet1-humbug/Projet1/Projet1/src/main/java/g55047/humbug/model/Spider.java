package g55047.humbug.model;

/**
 * Represents the spider that moves in the given direction as long as it does
 * not encounter an obstacle (a wall or an other animal).
 *
 * @author Marika Winska (55047)
 */
public class Spider extends Animal {

    private final String display = "S";

    /**
     * Constructor of the class Spider.
     *
     * @param positionOnBoard the position at which the spider is created.
     */
    public Spider(Position positionOnBoard) {
        super(positionOnBoard);
    }

    /**
     * Constructor of the class Spider.
     */
    public Spider() {
        super();
    }

    /**
     * Getter for the spider display.
     *
     * @return display of the spider.
     */
    @Override
    public String getDisplay() {
        return display;
    }

    /**
     * Moves the spider on the game board in the desired direction as long as it
     * does not encounter an obstacle.
     *
     * @param board the game board.
     * @param direction the direction in which the animal is moving,
     * @param animals an array of animals on the game board.
     * @return the new position.
     */
    @Override
    public Position move(Board board, Direction direction, Animal... animals) {
        Position position = this.getPositionOnBoard();
        while (position != null
                && board.isNextFree(position, direction, animals)
                && !board.isWall(position, direction)
                && !board.isNextWall(position, direction)) {
            position = moveOneCrawling(board, direction, animals);
        }
        position = testOnStar(board, position);

        return position;
    }

}
