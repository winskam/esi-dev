#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>

#include "position.h"
#include "observable.h"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

namespace abalone { namespace view {

/**
 * @brief The HexaCell class
 */
class HexaCell : public QGraphicsPolygonItem, public Observable
{
    /**
     * @brief zValMax z-val of selected items.
     */
    static const double zValMax;

    /**
     * @brief zval z-val at instanciation.
     */
    double zval;

    /**
     * @brief list_observer_ the list of observers.
     */
    std::list<Observer *> list_observer_;

protected :

    /**
     * @brief rad hexagon radius
     */
    double rad;

    /**
     * @brief dx the x coordinate of the center
     */
    double dx;

    /**
     * @brief dy the y coordinate of the center
     */
    double dy;

    /**
     * @brief mouseover mouse interaction booleans
     */
    bool mouseover;

    /**
    * @brief selected if the hexacell is selected
    */
    bool selected;

public :

    /**
     * @brief pos_ the position of the hexacell in a three dimensional system.
     */
    abalone::model::Position pos_;

    /**
     * @brief init sets the value of mouseover and selected to false.
     */
    void init();

    /**
     * @brief HexaCell the constructor for an hexacell.
     * @param pos position of the hexacell using the three axis method.
     * @param rad the length of the sides.
     * @param dx the position on the x axis on the screen.
     * @param dy the position on the y axis on the screen.
     * @param parent the QGraphicsItem that will contain this hexacell.
     */
    HexaCell(abalone::model::Position pos, double rad = 100, double dx = 0, double dy = 0, QGraphicsItem * parent = 0);

    /**
     * @brief paint draws this hexacell on the screen.
     * @param painter the system that will draw the hexacell.
     * @param option the style in which the hexacell will be drawn.
     * @param widget to draw.
     */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /**
     * @brief coord returns x and y coordinates of the hexacell.
     * @param x coordinate.
     * @param y coordinate.
     * @return a QPointF object containing the two coordinates.
     */
    inline QPointF coord(double x, double y) const;

    /**
     * @brief setLocation moves the hexacell to a new location.
     * @param x the new x position of the hexacell.
     * @param y the new y position of the hexacell.
     */
    inline void setLocation(double x, double y);

protected :

    /**
     * @brief hoverEnterEvent changes the mouseover attribute to true.
     * @param event the mouse hover the hexacell.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);

    /**
     * @brief hoverLeaveEvent changes the mouseover attribute to false.
     * @param event the mouse leaving the hexacell.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    /**
     * @brief mousePressEvent changes the selected attribute to its opposite.
     * @param event the mouse clicking on the hexacell.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

}}

#endif // HEXACELL_H
