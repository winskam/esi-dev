package g55047.humbug.model;

import static g55047.humbug.model.SquareType.GRASS;
import static g55047.humbug.model.SquareType.STAR;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

/**
 *
 * @author Marika Winska (55047)
 */
public class LadybirdTest {

    private Board board;
    private Animal[] animals;

    /**
     * Initialization of the game.
     */
    @BeforeEach
    public void setUp() {
        board = new Board(new Square[][]{
            {new Square(GRASS), new Square(GRASS), new Square(GRASS)},
            {new Square(GRASS), new Square(GRASS), new Square(GRASS)},
            {null, null, new Square(STAR)}
        });

        animals = new Animal[]{
            new Ladybird(new Position(1, 0)),
            new Ladybird(new Position(0, 2))
        };
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMove() {
        System.out.println("move_general");
        Ladybird instance = (Ladybird) animals[0];
        Position expResult = new Position(1, 2); //.next(Direction.EAST);
        Position result = instance.move(board, Direction.EAST, animals);
        assertEquals(expResult, result);
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMove_next_notfree() {
        System.out.println("move next case not free");
        Ladybird instance = (Ladybird) animals[0];
        animals[1].setPositionOnBoard(new Position(1, 1));
        Position expResult = new Position(1, 0); //don't move
        Position result = instance.move(board, Direction.EAST, animals);
        assertEquals(expResult, result);
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMove_next_onstar() {
        System.out.println("move next on star");
        Ladybird instance = (Ladybird) animals[1];
        Position expResult = new Position(2, 2);
        Position result = instance.move(board, Direction.SOUTH, animals);
        assertEquals(expResult, result);
        assertTrue(instance.isOnStar());
        assertEquals(GRASS, board.getSquareType(result));
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMove_next_notinside_2() {
        System.out.println("move next case null");
        Ladybird instance = (Ladybird) animals[0];
        Position expResult = null; // move and fall
        Position result = instance.move(board, Direction.WEST, animals);
        assertEquals(expResult, result);
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMoveWithWall() {
        Square withWall = new Square(GRASS);
        withWall.setEastWall(true);
        System.out.println("move with a wall");

        board = new Board(new Square[][]{
            {new Square(GRASS), new Square(GRASS), new Square(STAR), withWall},
            {null, new Square(GRASS), new Square(GRASS), null},
            {null, null, new Square(STAR), null}});

        animals = new Animal[]{
            new Ladybird(new Position(0, 0)),
            new Ladybird(new Position(0, 2))};

        Ladybird instance = (Ladybird) animals[1];
        Position expResult = new Position(0, 3);
        Position result = instance.move(board, Direction.EAST, animals);
        assertEquals(expResult, result);
    }

    /**
     * Test of move method, of class Ladybird.
     */
    @Test
    public void testMoveWithOppositeWall() {
        Square withWall = new Square(GRASS);
        withWall.setNorthWall(true);
        System.out.println("move with an opposite wall");

        board = new Board(new Square[][]{
            {new Square(GRASS), new Square(GRASS), new Square(STAR), withWall},
            {null, withWall, new Square(GRASS), null},
            {null, null, new Square(STAR), null}});

        animals = new Animal[]{
            new Ladybird(new Position(0, 0)),
            new Ladybird(new Position(0, 1))};

        Ladybird instance = (Ladybird) animals[1];
        Position expResult = new Position(0, 1);
        Position result = instance.move(board, Direction.SOUTH, animals);
        assertEquals(expResult, result);
    }

}
