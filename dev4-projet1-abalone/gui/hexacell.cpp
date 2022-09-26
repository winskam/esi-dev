#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"
#include "hexacell.h"

namespace abalone { namespace view {

double const HexaCell::zValMax = 10000;//arbitrary

HexaCell::HexaCell(abalone::model::Position pos,  double rad, double dx, double dy, QGraphicsItem * parent)
    : QGraphicsPolygonItem(parent), list_observer_ (),rad(rad), dx(dx), dy(dy), mouseover(false), selected(false), pos_(pos)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4 / 6;

    QPolygonF polygon;
    auto&& corners = orbit({dx, dy}, 6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if(selected)
    {
        QPen pen(Qt::black, 5);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::red);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::red);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    mouseover = false;
    update();
}

void HexaCell::init() {
    mouseover = false;
    selected = false;
}
void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    notifyObservers();
    selected = !selected;
    update();
    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

}}

#pragma GCC diagnostic pop
