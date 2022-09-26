package g55047.humbug.model;

/**
 * Square on the board. A square has a type grass or star and has one or more
 * walls or no walls at all. A square doesn't know where it is on the board.
 *
 * @author Marika Winska (55047)
 */
public class Square {

    private SquareType type;
    private boolean northWall;
    private boolean southWall;
    private boolean westWall;
    private boolean eastWall;

    /**
     * Constructor of Square with wall(s) on board.
     *
     * @param northWall a wall north of the square.
     * @param southWall a wall south of the square.
     * @param westWall a wall west of the square.
     * @param eastWall a wall east of the square.
     */
    public Square(boolean northWall, boolean southWall, boolean westWall, boolean eastWall) {
        this.northWall = northWall;
        this.southWall = southWall;
        this.westWall = westWall;
        this.eastWall = eastWall;
        northWall = false;
        southWall = false;
        westWall = false;
        eastWall = false;
    }

    /**
     * Constructor of Square on board.
     *
     * @param type Square is grass or star.
     */
    public Square(SquareType type) {
        this.type = type;
    }

    /**
     * Constructor of the class Square.
     */
    public Square() {
        this.type = SquareType.GRASS;
        this.northWall = false;
        this.southWall = false;
        this.westWall = false;
        this.eastWall = false;
    }

    /**
     * Simple setter of a north wall.
     *
     * @param northWall a wall north of the square.
     */
    public void setNorthWall(boolean northWall) {
        this.northWall = northWall;
    }

    /**
     * Simple setter of a south wall.
     *
     * @param southWall a wall south of the square.
     */
    public void setSouthWall(boolean southWall) {
        this.southWall = southWall;
    }

    /**
     * Simple setter of a west wall.
     *
     * @param westWall a wall west of the square.
     */
    public void setWestWall(boolean westWall) {
        this.westWall = westWall;
    }

    /**
     * Simple setter of a east wall.
     *
     * @param eastWall a wall east of the square.
     */
    public void setEastWall(boolean eastWall) {
        this.eastWall = eastWall;
    }

    /**
     * Simple getter of type.
     *
     * @return type of Square.
     */
    public SquareType getType() {
        return type;
    }

    /**
     * Simple setter of type.
     *
     * @param type of Square.
     */
    public void setSquareType(SquareType type) {
        this.type = type;
    }

    /**
     * Checks if there is a wall in a given direction.
     *
     * @param direction the direction in which to check
     * @return true if there is a wall, false otherwise.
     */
    public boolean hasWall(Direction direction) {
        boolean wall = false;
        switch (direction) {
            case NORTH:
                wall = northWall;
                break;
            case SOUTH:
                wall = southWall;
                break;
            case WEST:
                wall = westWall;
                break;
            case EAST:
                wall = eastWall;
        }

        return wall;
    }

}
