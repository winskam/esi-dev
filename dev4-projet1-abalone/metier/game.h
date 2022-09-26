#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "observable.h"
#include <ostream>

namespace abalone { namespace view { class View; class MainWindow; }}

namespace abalone { namespace model {

/*!
 * \brief Class that represents the game.
 *
 * This class is the current state of the game.
 */
class Game: public Observable {

    /*!
     * \brief list with all the observers of this observable.
     */
    std::list<Observer *> list_observer_;

    /*!
     * \brief The player with the white marbles.
     */
    Player playerWhite_;

    /*!
     * \brief The player with the black marbles.
     */
    Player playerBlack_;

    /*!
     * \brief The player that is playing for the moment.
     */
    Player * playerTurn_;

    /*!
     * \brief the actual board of the current game.
     */
    Board gameBoard_;

public :

    /*!
     * \brief Default destructor.
     */
    virtual ~Game() = default;

    /*!
     * \brief Game Constructor for the class game
     */
    Game();

    /*!
     * \brief list_observer lists the list of observers of this class
     * \return the list of observers
     */
    inline std::list<Observer *> list_observer();

    /*!
     * \brief getter for the player whos turn it is.
     *
     * \return the player whos turn it is.
     */
    inline Player * playerTurn() const;

    /*!
     * \brief getter for the player that is playing with the white marbles.
     *
     * \return the player that is playing with the white marbles.
     */
    inline Player & playerWhite();

    /*!
     * \brief getter for the player that is playing with the black marbles.
     *
     * \return the player that is playing with the black marbles.
     */
    inline Player & playerBlack();

    /*!
     * \brief checks if someone won the game.
     *
     * \return true if a player won, false otherwise.
     *
     * A player won if the other has lost 6 marbles.
     */
    bool checkWon() ;

    /*!
     * \brief makes a marble move from a certain position to another. The move can
     * anly be made if it is possible and if the player whos turn it is tries to
     * move a marble of his own color.
     *
     *
     * \param posBegin the initial position of the first marble of a group.
     *
     * \param posEnd the position where the first marble has to go.
     *
     * \throw an exception will be thrown if the movement that the player tries to
     *  make is not possible.
     */
    void makeMove(Position posBegin, Position posEnd);

    /*!
     * \brief makes a group of marvels move from a certain position to another. The move can
     * anly be made if it is possible and if the player whos turn it is tries to
     * move a group of marbles of his own color.
     *
     *
     * \param posBeginFirst the initial position of the first marble of a group.
     *
     * \param posBeginLast the initial position of the last marble of a group.
     *
     * \param posEndFirst the position where the first marble has to go.
     *
     * \throw an exception will be thrown if the movement that the player tries to
     *  make is not possible.
     */
    void makeMove(Position posBeginFirst, Position posBeginLast, Position posEndFirst);

    /*!
     * \brief checks if a move is possible from a certain position to another. The only thing that is
     * checked is wether the marble at the position is the marble of the player making the move.
     *
     * \param posBegin the initial position of the marble.
     *
     * \return true if the move is possible.
     *
     * \throw if the move is not possible an exception will be thrown.
     */
    bool isMovePossible(Position posBegin);

    /*!
     * \brief checks if a move is possible from a certain position to another. The only thing that is
     * checked is wether the marbles at the positions are marbles of the player making the move.
     *
     * \param posBeginFirst the initial position of the first marble of a group.
     *
     * \param posBeginLast the initial position of the last marble of a group.
     *
     *
     * \return true if the move is possible, false otherwise.
     *
     * \throw if the move is not possible an exception will be thrown.
     */
    bool isMovePossible(Position posBeginFirst, Position posBeginLast);

    /*!
     * \brief cleans the board at the end of the game to avoid having memory leaks.
     */
    void cleanBoard();

    /*!
     * \brief gets a movement in a string and tries to perform that movement.
     *
     * \param string the movement to perform.
     *
     */
    void stringToMovement(std::string string);


    /*!
     * \brief resets the state of the game to the initial state of a new game
     */
    void reset();

private :

    /*!
     * \brief sets the turn to a player.
     *
     * \param the player whos turn it will be.
     *
     */
    void setTurn(Player &player);

    /*!
     * \brief changes whos turn it is to play.
     */
    void changeTurn();

    friend class abalone::view::View;

    friend class abalone::view::MainWindow;

protected :

    /*!
     * \brief a getter for the gameboard.
     *
     * \return the gameboard of this game.
     */
    inline Board getBoard();

};

abalone::model::Player * abalone::model::Game::playerTurn() const {
    return playerTurn_;
}

abalone::model::Board abalone::model::Game::getBoard(){
    return gameBoard_;
}

abalone::model::Player & abalone::model::Game::playerWhite() {
    return playerWhite_;
}

abalone::model::Player & abalone::model::Game::playerBlack() {
    return playerBlack_;
}

std::list<Observer *> abalone::model::Game::list_observer() {
    return list_observer_;
}

}}

#endif // GAME_H
