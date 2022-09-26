#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include "observable.h"

class Observable;

/*!
 * \brief abstract class that forms the base of all observable classes
 *
 * \sa Observable
 *
 * \see https://en.wikipedia.org/wiki/Observer_pattern
 *
 * \see  NVS  Disclaimer: note that this class was completely implemented by Nicolas Vansteenkiste and was
 * found on in the course material.
 */

class Observer {

public :

    /*!
     * \brief virtual method that will be called when an observable notified this class that it needed
     * to be updated
     *
     * \param subject the object that notified
     * \see Observable::notifyObservers().
     */
    virtual void update(const Observable * subject) = 0;

    /*!
     * \brief virtual default destructor
     */
    virtual ~Observer() = default;

    /*!
     * \brief default copy constructor
     *
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observer(const Observer &) = default;

protected :

    /*!
     * \brief protected constructor to avoid construction besides heritage
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observer() = default;

};

#endif // OBSERVER_H
