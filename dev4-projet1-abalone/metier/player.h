#ifndef PLAYER_H
#define PLAYER_H

namespace abalone { namespace model {

/*!
 * \brief class that represents a player
 *
 * player 1 will play the black marbles, player 2 the white ones.
 */
class Player {

    /*!
     * \brief the number of the player
     */
    int id_;

    /*!
     * \brief the amount of marbles the player has left.
     */
    int nbMarbles_;

public :

    /*!
     * \brief Constructor.
     *
     * constructs a player with a number between 1 and 2.
     * every player constructed starts with 14 marbles.
     *
     * \param id the number of the player
     *
     * \throw std::invalid_argument if the id is not 1 or 2.
     */
    Player(int id);

    /*!
     * \brief getter for the number of the player
     *
     * \return the number of the player
     */
    inline int id() const;

    /*!
     * \brief getter for the amount of marbles the player has left.
     *
     * \return the amount of marbles the player has left.
     */
    inline int nbMarbles() const;

    /*!
     * \brief reduces the number of marble the players has by 1.
     */
    void deleteMarble();

    /**
     * @brief operator = Assignement operator
     * @param f the player that will be affected to this player
     * @return the player
     */
    Player& operator= (const Player& f);

};

int abalone::model::Player::id() const {
    return id_;
}

int abalone::model::Player::nbMarbles() const {
    return nbMarbles_;
}

}}

#endif // PLAYER_H
