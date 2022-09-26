package g55047.humbug;

import g55047.humbug.controller.Controller;
import g55047.humbug.model.Game;
import g55047.humbug.view.text.View;

/**
 * Class that starts the game.
 *
 * @author Marika Winska (55047)
 */
public class Main {

    public static void main(String[] args) {
        Controller controller = new Controller(new Game(), new View());
        controller.startGame(1);
    }

}
