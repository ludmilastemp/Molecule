#include "molecule.h"

/**************************************************************************/

Molecule::Molecule (size_t init_size, const Vector& init_coord, const Vector& init_speed)
    : Object(1), size(init_size), coord(init_coord), speed(init_speed)
{}

Molecule::Molecule (bool isDraw, size_t init_size, const Vector& init_coord, const Vector& init_speed)
    : Object(isDraw), size(init_size), coord(init_coord), speed(init_speed)
{}

/**************************************************************************/

ObjectType Molecule::type () const 
{
    return ObjectTypeMolecule;
}         

void Molecule::setCoordShift (coord_t x, coord_t y)
{
    coord.setX (coord.getX() + x);
    coord.setY (coord.getY() - y);
}

void Molecule::draw (GraphicsCtx& ctx) //const
{
    sf::CircleShape circle;

    circle.setRadius(size);
    circle.setPosition(coord.getX() - size, coord.getY() - size);
    circle.setFillColor (sf::Color::Green);

    // circle.setOutlineColor(sf::Color::Red);
    // circle.setOutlineThickness(5);
    // circle.setPointCount (100);

    ctx.window.draw(circle);
}

/**************************************************************************/
