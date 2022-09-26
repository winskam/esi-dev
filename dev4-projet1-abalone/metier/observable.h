#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "observer.h"
#include <set>

class Observer;

/*!
 * \brief abstract Class that defines an observable class
 *
 * \see NVS  Disclaimer: note that this class was completely implemented by Nicolas Vansteenkiste and was
 * found in the course material.
 *
 * An observable class is a class that will notify his observers that a change was made.
 *
 */
class Observable {

public :

    /*!
     * \brief Default destructor.
     */
    virtual ~Observable() = default;

    /*!
     * \brief default copy constructor.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable(const Observable &) = default;

    /*!
     * \brief default deplacement constructor.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable(Observable &&) = default;

    /*!
     * \brief method that lets an observable register an observer that will obser that object
     *
     * \param observer a pointer to the observer candidate.
     */
    virtual void registerObserver(Observer * observer) final;

    /*!
     * \brief method that deletes an observer of the list of observers of an observable.
     *
     * \param observer the address of the observer to delete.
     */
    virtual void unregisterObserver(Observer * observer) final;

protected :

    /*!
     * \brief protected constructor to avoid construcor by heritage.
     */
    Observable() = default;

    /*!
     * \brief this method will notify all the observers of this class that a change was made in this class.
     *
     * \sa Observer::update(const Subject *).
     */
    virtual void notifyObservers() const final;

    /*!
     * \brief the set of all observers of this class.
     */
    std::set<Observer *> observers_ { };

};

#endif
