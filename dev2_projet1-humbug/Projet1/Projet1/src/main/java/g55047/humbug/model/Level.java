package g55047.humbug.model;

import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;

/**
 * Provides the level of the game.
 *
 * @author Marika Winska (55047)
 */
public class Level {

    private final Board board;
    private final Animal[] animals;
    private final int nMoves;

    /**
     * Constructor of the class Level.
     *
     * @param board for the corresponding level.
     * @param animals for the corresponding level.
     * @param nMoves for the corresponding level.
     */
    private Level(Board board, Animal[] animals, int nMoves) {
        this.board = board;
        this.animals = animals;
        this.nMoves = nMoves;
    }

    /**
     * Constructor of the class Level.
     */
    public Level() {
        this.board = null;
        this.animals = null;
        this.nMoves = 0;
    }

    /**
     * Getter of board.
     *
     * @return the board.
     */
    public Board getBoard() {
        return board;
    }

    /**
     * Getter of aninals.
     *
     * @return animals.
     */
    public Animal[] getAnimals() {
        return animals;
    }

    /**
     * Getter of number of moves in the level.
     *
     * @return number of moves.
     */
    public int getnMoves() {
        return nMoves;
    }

    /**
     * Returns the level of the game.
     *
     * @param level played.
     * @return level played.
     */
    public static Level getLevel(int level) {
        return readLevel(level);
    }

    private static Level readLevel(int n) {
        try {
            var objectMapper = new ObjectMapper();
            var inputStream = Level.class.getResourceAsStream("/data/level-" + n + ".json");
            var level = objectMapper.readValue(inputStream, Level.class);
            return level;
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }

        return null;
    }

}
