#include "button.h"

void DrawButton (const Button& button, GraphicsCtx& ctx);

/**************************************************************************/

Button::Button (const VectorDec& init_corner, const VectorDec& init_size, Action& init_action)//, const Color& init_color)
    : Object(0), corner(init_corner), size(init_size)//, color(init_color)
{
    actions.push_back (&init_action);
}

Button::Button (bool isDraw, const VectorDec& init_corner, const VectorDec& init_size, Action& init_action)//, const Color& init_color)
    : Object(isDraw), corner(init_corner), size(init_size)//, color(init_color)
{
    actions.push_back (&init_action);
}

/**************************************************************************/

ObjectType Button::type () const 
{
    return ObjectTypeButton;
}         

void Button::draw (GraphicsCtx& ctx) //const
{
    DrawButton (*this, ctx); 
}

/**************************************************************************/

bool IsButton (const sf::Vector2i& pos, const Button& button)
{
    return 
        button.corner.x <= pos.x && 
                           pos.x <= button.corner.x + button.size.x &&
        button.corner.y <= pos.y && 
                           pos.y <= button.corner.y + button.size.y;

}

void DrawButton (const Button& button, GraphicsCtx& ctx)
{
    // Color buttonColor = button.color * 255;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(button.size.x, button.size.y));
    // rectangle.setFillColor(sf::Color (buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a));
    rectangle.setFillColor(sf::Color::Red);
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x, button.corner.y);
    ctx.window.draw(rectangle);
}

/**************************************************************************/
