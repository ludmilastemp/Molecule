#include "controllerMolecule.h"

/**************************************************************************/

ControllerMolecule::ControllerMolecule (ModelButton& init_modelButton, ViewButton& init_viewButton)
    : modelButton(init_modelButton), viewButton(init_viewButton)
{}

/**************************************************************************/

void ControllerMolecule::update (GraphicsCtx& ctx)
{
    modelButton.update (ctx);
    viewButton.update (ctx);
}

/**************************************************************************/
