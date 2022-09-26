#ifndef VIEW_H
#define VIEW_H

#include "observer.h"
#include "game.h"

//class Game;

namespace abalone { namespace view {

/*!
 * \brief console observer of the class model::Game.
 */
class View final : public Observer {

    /*! \brief the observed class. */
    model::Game * subject_;

public :

    /*!
     * \brief constructor.
     *
     * This constructor registers itself as observer of the paramater.
     * At the end the class is updated.
     *
     * \param observable the address of the observed game.
     */
    View(model::Game * observable);

    /*!
     * \brief destructor.
     *
     * when this object is deleted, it is first unregistered as observer.
     */
    virtual ~View();

    /*!
     * \brief updates the observer by printing the gameboard and whos turn it is.
     *
     * \param subject the game that notified a change was made.
     */
    virtual void update(const Observable * subject) override;

    /*!
     * \brief printGame prints the current state of the game into the console.
     */
    void printGame();

    /*!
     * \brief printWin prints a message to tell that one player just won.
     */
    void printWin();

};

}}

#endif // VIEW_H
