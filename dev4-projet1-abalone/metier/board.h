#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <list>
#include <array>
#include <optional>
#include <marble.h>
#include <iostream>

namespace abalone { namespace model {

/*!
 * \brief Class that represents a board in the game abalone.
 *
 * with the size of the board and
 * the position of all the marbles on the board, the game board is fully represented.
 */
class Board {

    /*!
     * \brief The size of the game board.
     *
     * This number is constant
     */
    const static int size_ = 9;

    /*!
     * \brief an array with all the marbles on the board
     */
    std::array<std::array<std::array<std::optional<Marble*>,size_>,size_>, size_> marbles_ ;

public :


    /*!
     * \brief Constructor.
     *
     * The size of the board is given. The amount of black and white
     * marbles will be set to 14. the marbles are set to the right position
     *
     * The size cannot be null.
     *
     * \param playerBlack the first player of the board
     *
     * \param playerWhite the second player of the board
     */
    Board(Player & playerBlack, Player & playerWhite);

    /*!
     * \brief getter for the size of the board
     *
     * \return size of the board
     */
    inline int size() const;

    /*!
     * \brief getter for the vector with the marbles on the board
     *
     * \return the vector with the marbles on the board
     */
    inline std::array<std::array<std::array<std::optional<Marble*>,size_>,size_>,size_> marbles() const;

    /*!
     * \brief checks for a marble at a certain position
     *
     * \param position the position to check
     *
     * \return the marble at this position,
     * if there is no marble it returns null
     */
    Marble * marbleAtPosition(Position position);

    /*!
     * \brief checks if a position is possible
     * according to the size of the board
     *
     * \param position the position to check
     *
     * \return true if the position is possible, false otherwise
     */
    bool isPosPossible(Position position);

    /*!
     * \brief checks for a player at a certain position
     *
     * \param position to check
     *
     * \return the player at this position,
     * if there is no player it returns null
     */
    Player * playerAtPosition(Position position);

    /*!
     * \brief deletes the marble at this position
     *
     * \param position the position to delete
     */
    void deleteAtPosition(Position position);

    /*!
     * \brief makes a marble move from a certain position to another.
     *
     * \param posBegin the initial position of the marble.
     *
     * \param posEnd the position where the marble has to go
     */
    void changePosition(Position posBegin, Position posEnd);

};

int abalone::model::Board::size() const {
    return size_;
}

std::array<std::array<std::array<std::optional<abalone::model::Marble*>,9>,9>,9> abalone::model::Board::marbles() const {
    return marbles_;
}

}}

#endif // BOARD_H
