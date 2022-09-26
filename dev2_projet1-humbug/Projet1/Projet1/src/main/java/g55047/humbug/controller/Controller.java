package g55047.humbug.controller;

import g55047.humbug.model.Direction;
import g55047.humbug.model.LevelStatus;
import g55047.humbug.model.Model;
import g55047.humbug.model.Position;
import g55047.humbug.view.text.InterfaceView;

/**
 * Manages game dynamics and view update as the game progresses.
 *
 * @author Marika Winska (55047)
 */
public class Controller {

    private final Model game;
    private final InterfaceView view;

    /**
     * Constructor of the class.
     *
     * @param game represents the model.
     * @param view represents the view.
     */
    public Controller(Model game, InterfaceView view) {
        this.game = game;
        this.view = view;
    }

    /**
     * Method used to play. Starts the model, displays the board, asks for a
     * position and direction and attempts to move.
     *
     * @param level played.
     */
    public void startGame(int level) {
        game.startLevel(level);
        game.updateStatus();
        Position position;
        while (game.getLevelStatus() != LevelStatus.FAIL && game.getLevelStatus() != LevelStatus.WIN) {
            view.displayRemainingMoves(game.getRemainingMoves());
            view.displayBoard(game.getBoard(), game.getAnimals());
            do {
                position = view.askPosition();
            } while (game.isFree(position));
            Direction direction = view.askDirection();
            try {
                game.move(position, direction);
            } catch (Exception e) {
                view.displayError("Incomplete game !");
            }
        }

        if (game.getLevelStatus() == LevelStatus.WIN) {
            view.displayError("Congrats !");
            try {
                startGame(++level);
            } catch (Exception e) {
                view.displayError("The game is finished !");
            }
        } else if (game.getLevelStatus() == LevelStatus.FAIL) {
            view.displayError("You lost !");
            startGame(level);
        }
    }

}
