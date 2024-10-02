#include "viewButton.h"

/**************************************************************************/

ViewButton::ViewButton (std::vector <Button> *init_buttons)
    :buttons (init_buttons)
{}

/**************************************************************************/

void ViewButton::update (GraphicsCtx& ctx)
{
    assert (buttons);
    for (int i = 0; i < buttons->size(); i++)
    {
        (*buttons)[i].draw(ctx);
    }
}

/**************************************************************************/
