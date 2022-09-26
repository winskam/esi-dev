package g55047.humbug.view.text;

import g55047.humbug.model.Animal;
import g55047.humbug.model.Board;
import g55047.humbug.model.Direction;
import g55047.humbug.model.Position;
import g55047.humbug.model.SquareType;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * A class that displays the game board and interacts with the user.
 *
 * @author Marika Winska (55047)
 */
public class View implements InterfaceView {

    /**
     * Display with red color.
     */
    public static final String RED = "\033[31m";

    /**
     * Display with blue color.
     */
    public static final String BLUE = "\033[34m";

    /**
     * Display with the color green in the background.
     */
    public static final String BG_GREEN = "\033[42m";

    /**
     * Display with the color red in the background.
     */
    public static final String BG_RED = "\033[41m";

    /**
     * Stops the display with colors. Back to basic settings.
     */
    public static final String RESET = "\033[0m";

    /**
     * Displays the game board.
     *
     * @param board the game board to display.
     * @param animals an array of animals on the game board.
     */
    @Override
    public void displayBoard(Board board, Animal... animals) {
        String[][] boardF = makeString(board, animals);
        for (String[] boardFRow : boardF) {
            for (String boardFColumn : boardFRow) {
                System.out.print(boardFColumn);
            }
            System.out.println("");
        }
    }

    /**
     * Creates the display of the game board with a 2-dimensional array of
     * strings.
     *
     * @param board the game board to make.
     * @param animals an array of animals on the game board.
     * @return a 2-dimensional array of strings with the game board.
     */
    String[][] makeString(Board board, Animal... animals) {
        String[][] boardF = new String[4 * board.getNbRow() + 1][4 * board.getNbColumn() + 1];
        for (String[] boardFRow : boardF) {
            for (int j = 0; j < boardFRow.length; j++) {
                boardFRow[j] = " ";
            }
        }

        for (int a = 0; a < board.getNbRow(); a++) {
            for (int b = 0; b < board.getNbColumn(); b++) {
                if (board.isInside(new Position(a, b))) {
                    int row = a * 4;
                    int column = b * 4;
                    for (int p = 0; p < 5; p++) {
                        boardF[row][column + p] = BG_GREEN + "-" + RESET;
                    }
                    row++;
                    for (int q = 0; q < 3; q++) {
                        for (int r = 0; r < 5; r++) {
                            if ((column + r) % 4 == 0) {
                                boardF[row][column + r] = BG_GREEN + "|" + RESET;
                            } else {
                                boardF[row][column + r] = BG_GREEN + " " + RESET;
                            }
                        }
                        row++;
                    }
                    for (int p = 0; p < 5; p++) {
                        boardF[row][column + p] = BG_GREEN + "-" + RESET;
                    }
                    for (Animal an : animals) {
                        if (an.getPositionOnBoard().equals(new Position(a, b)) && !an.isOnStar()) {
                            boardF[4 * a + 2][4 * b + 2] = BG_GREEN + an.getDisplay() + RESET;
                        }
                    }
                    if (board.getSquareType(new Position(a, b)) == SquareType.STAR) {
                        boardF[4 * a + 2][4 * b + 2] = BG_GREEN + RED + "*" + RESET;
                    }
                    if (board.isWall(new Position(a, b), Direction.NORTH)) {
                        boardF[4 * a + 1][4 * b + 2] = BG_RED + " " + RESET;
                    }
                    if (board.isWall(new Position(a, b), Direction.SOUTH)) {
                        boardF[4 * a + 3][4 * b + 2] = BG_RED + " " + RESET;
                    }
                    if (board.isWall(new Position(a, b), Direction.WEST)) {
                        boardF[4 * a + 2][4 * b + 1] = BG_RED + " " + RESET;
                    }
                    if (board.isWall(new Position(a, b), Direction.EAST)) {
                        boardF[4 * a + 2][4 * b + 3] = BG_RED + " " + RESET;
                    }
                }
            }
        }

        return boardF;
    }

    /**
     * Displays an error message.
     *
     * @param message the message to be displayed.
     */
    @Override
    public void displayError(String message) {
        System.out.println(message);
    }

    /**
     * Asks the position of the animal on the row.
     *
     * @return position on the row.
     */
    public int askRow() {
        Scanner positionIn = new Scanner(System.in);
        boolean hasRow = false;
        int row = 0;
        while (!hasRow) {
            System.out.print("Enter the position on the row "
                    + "of the animal you want to move : ");
            try {
                row = positionIn.nextInt();
                hasRow = true;
            } catch (InputMismatchException e) {
                positionIn.nextLine();
            }
        }

        return row;
    }

    /**
     * Asks the position of the animal on the column.
     *
     * @return position on the column.
     */
    public int askColumn() {
        Scanner positionIn = new Scanner(System.in);
        boolean hasColumn = false;
        int column = 0;
        while (!hasColumn) {
            System.out.print("Enter the position on the column "
                    + "of the animal you want to move : ");
            try {
                column = positionIn.nextInt();
                hasColumn = true;
            } catch (InputMismatchException e) {
                positionIn.nextLine();
            }
        }

        return column;
    }

    /**
     * Asks the user to encode a position.
     *
     * @return the position type Position.
     */
    @Override
    public Position askPosition() {
        int row = askRow();
        int column = askColumn();

        return new Position(row, column);
    }

    /**
     * Asks the user to encode a direction in which the animal will move.
     *
     * @return the direction of the movement.
     */
    @Override
    public Direction askDirection() {
        Scanner direction = new Scanner(System.in);
        String directionAnimal;
        do {
            System.out.print("Enter the direction : ");
            directionAnimal = direction.next();
        } while (!(directionAnimal.equals("NORTH") || directionAnimal.equals("SOUTH")
                || directionAnimal.equals("WEST") || directionAnimal.equals("EAST")));

        Direction directionA = Direction.valueOf(directionAnimal);

        return directionA;
    }

    /**
     * Displays the remaining moves for the level played.
     *
     * @param level played.
     */
    @Override
    public void displayRemainingMoves(int level) {
        System.out.println(level + " remaining moves !");
    }

}
