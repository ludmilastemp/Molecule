#include "molecular.h"

/**************************************************************************/

Molecular::Molecular (const Vector& init_coord, const Vector& init_speed)
    : Object(1), coord(init_coord), speed(init_speed)
{}

Molecular::Molecular (bool isDraw, const Vector& init_coord, const Vector& init_speed)
    : Object(isDraw), coord(init_coord), speed(init_speed)
{}

/**************************************************************************/

ObjectType Molecular::type () const 
{
    return ObjectTypeMolecular;
}         

void Molecular::setCoordShift (coord_t x, coord_t y)
{
    coord.setX (coord.getX() + x);
    coord.setY (coord.getY() - y);
}

void Molecular::draw (GraphicsCtx& ctx) //const
{
    sf::CircleShape circle;

    circle.setRadius(10);
    circle.setPosition(coord.getX(), coord.getY());
    circle.setFillColor (sf::Color::Green);

    // circle.setOutlineColor(sf::Color::Red);
    // circle.setOutlineThickness(5);
    // circle.setPointCount (100);

    ctx.window.draw(circle);
}

/**************************************************************************/
