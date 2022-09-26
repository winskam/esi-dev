package g55047.humbug.model;

/**
 * The Game class is used to build the game and implement the Model interface.
 *
 * @author Marika Winska (55047)
 */
public class Game implements Model {

    private Board board;
    private Animal[] animals;
    private int remainingMoves;
    // private int currentLevel;
    private LevelStatus currentStatus;

    /**
     * Getter for the board.
     *
     * @return the board.
     */
    @Override
    public Board getBoard() {
        return this.board;
    }

    /**
     * Getter for the array of animals.
     *
     * @return the array of animals.
     */
    @Override
    public Animal[] getAnimals() {
        return this.animals;
    }

    /**
     * Initializes the game board and the animals for the desired level.
     *
     * @param level the level that's going to be played.
     */
    @Override
    public void startLevel(int level) {
        this.board = Level.getLevel(level).getBoard();
        this.animals = Level.getLevel(level).getAnimals();
        this.remainingMoves = Level.getLevel(level).getnMoves();
    }

    /**
     * Updates the level status.
     */
    @Override
    public void updateStatus() {
        if (board == null || animals == null) {
            currentStatus = LevelStatus.NOT_STARTED;
        } else {
            boolean isOver = true;
            boolean isFallen = false;
            for (Animal animal : animals) {
                if (!animal.isOnStar()) {
                    isOver = false;
                }
                if (animal.getPositionOnBoard() == null) {
                    isFallen = true;
                }
            }
            if (isOver) {
                currentStatus = LevelStatus.WIN;
            } else if (remainingMoves == 0) {
                currentStatus = LevelStatus.FAIL;
            }
            if (isFallen) {
                currentStatus = LevelStatus.FAIL;
            } else if (getRemainingMoves() > 0 && !isOver) {
                currentStatus = LevelStatus.IN_PROGRESS;
            }
        }
    }

    /**
     * Makes the move if it is permitted.
     *
     * @param position the position where the animal wants to move.
     * @param direction the direction in which the animal wants to move.
     */
    @Override
    public void move(Position position, Direction direction) {
        if (board == null || animals == null) {
            throw new IllegalStateException("The board or the animals are null.");
        }
        for (Animal animal : animals) {
            if (!(animal.isOnStar()) && position.equals(animal.getPositionOnBoard())) {
                animal.move(board, direction, animals);
                remainingMoves--;
                updateStatus();
            }
        }
    }

    /**
     * Checks if the position is free.
     *
     * @param position the position to be checked.
     * @return true if the position is free, false otherwise.
     */
    @Override
    public boolean isFree(Position position) {
        boolean free = true;
        for (Animal animal : animals) {
            if (animal.getPositionOnBoard().equals(position)) {
                free = false;
            }
        }

        return free;
    }

    /**
     * Getter for the number of remaining moves for the level played.
     *
     * @return remaining moves.
     */
    @Override
    public int getRemainingMoves() {
        return remainingMoves;
    }

    /**
     * Getter for level status.
     *
     * @return level status.
     */
    @Override
    public LevelStatus getLevelStatus() {
        return currentStatus;
    }

}
