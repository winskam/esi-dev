package g55047.humbug.view.text;

import g55047.humbug.model.Animal;
import g55047.humbug.model.Board;
import g55047.humbug.model.Direction;
import g55047.humbug.model.Position;

/**
 * Class that implements the game interface.
 *
 * @author Marika Winska (55047)
 */
public interface InterfaceView {

    /**
     * Displays the game board.
     *
     * @param board the game board to display.
     * @param animals an array of animals on the game board.
     */
    public void displayBoard(Board board, Animal... animals);

    /**
     * Asks the user to encode a position.
     *
     * @return the position type Position.
     */
    public Position askPosition();

    /**
     * Asks the user to encode a direction in which the animal will move.
     *
     * @return the direction of the movement.
     */
    public Direction askDirection();

    /**
     * Displays an error message.
     *
     * @param message the message to be displayed.
     */
    public void displayError(String message);

    /**
     * Displays the remaining moves for the level played.
     *
     * @param level played.
     */
    public void displayRemainingMoves(int level);

}
