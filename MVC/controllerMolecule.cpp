#include "controllerMolecule.h"

/**************************************************************************/

ControllerMolecule::ControllerMolecule (ModelButton& init_modelButton, ViewButton& init_viewButton)
    : modelButton(init_modelButton), viewButton(init_viewButton)
{}

/**************************************************************************/

void ControllerMolecule::update (GraphicsCtx& ctx)
{
    if (ctx.checkEvent == true &&
        ctx.event.type == sf::Event::MouseButtonPressed &&
        ctx.event.mouseButton.button == sf::Mouse::Left)
    {
        // printf ("Mouse button pressed\n");
        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);

        modelButton (pos);

        ctx.checkEvent = false;
    }

    viewButton (ctx);
}

/**************************************************************************/
