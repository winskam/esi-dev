#ifndef MARBLE_H
#define MARBLE_H

#include "player.h"
#include "position.h"

namespace abalone { namespace model {

/*!
 * \brief Class that represents the marbles.
 *
 * a marbles contains the player that owns this marble,
 * it will determine its color.
 */
class Marble {

    /*!
    * \brief The player whos marble it is.
    */
    Player * player_;

public :

    /*!
    * \brief Constructor.
    *
    * A marble is created with a player, it determines.
    *
    * \param play the player whos marble it is.
    *
    * \throw std::invalid_argument if player is null.
    */
    Marble(Player & play);

    /*!
     * \brief getter for the player of the marble.
     *
     * \return the player of the marble.
     */
    inline Player * player();

};

abalone::model::Player * abalone::model::Marble::player() {
    return player_;
}

}}

#endif // MARBLE_H
