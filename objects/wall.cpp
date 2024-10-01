#include "wall.h"

/**************************************************************************/

Wall::Wall (Vector init_corner1, Vector init_corner2, Vector init_corner3, Vector init_corner4)
    : Object(isDraw), corner1(init_corner1), corner2(init_corner2), 
                      corner3(init_corner3), corner4(init_corner4)
{}

Wall::Wall (bool isDraw, Vector init_corner1, Vector init_corner2, Vector init_corner3, Vector init_corner4)
    : Object(isDraw), corner1(init_corner1), corner2(init_corner2), 
                      corner3(init_corner3), corner4(init_corner4)
{}

/**************************************************************************/

ObjectType Wall::type () const 
{
    return ObjectTypeWall;
}         

void Wall::draw (GraphicsCtx& ctx) //const
{
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(corner2.getX() - corner1.getX(), 
                                   corner3.getY() - corner1.getY()));
    rectangle.setPosition(corner1.getX(), corner1.getY());
    rectangle.setFillColor (sf::Color::Blue);

    ctx.window.draw(rectangle);
}

/**************************************************************************/
