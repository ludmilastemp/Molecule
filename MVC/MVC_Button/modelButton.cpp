#include "modelButton.h"

/**************************************************************************/

ModelButton::ModelButton ()
{}

/**************************************************************************/

void ModelButton::addButton (Button button)
{
    buttons.push_back (button);
}

void ModelButton::update (GraphicsCtx& ctx)
{
    if (ctx.checkEvent == true &&
        ctx.event.type == sf::Event::MouseButtonPressed &&
        ctx.event.mouseButton.button == sf::Mouse::Left)
    {
        // printf ("Mouse button pressed\n");
        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
        for (int i = 0; i < buttons.size(); i++)
        {
            Button& button = buttons[i];
            if (IsButton (pos, button))
            {
                for (size_t act = 0; act < button.actions.size(); act++)
                {
                    (*button.actions[act])();
                }
            }
        }
    }

    ctx.checkEvent = false;
}

/**************************************************************************/
