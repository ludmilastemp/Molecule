#ifndef STL_CONTROLLER_MOLECULE
#define STL_CONTROLLER_MOLECULE

#include "MVC_Button/modelButton.h"
#include "MVC_Button/viewButton.h"

class ControllerMolecule
{
public:
    ModelButton& modelButton;
    ViewButton&  viewButton;

    ControllerMolecule (ModelButton& modelButton, ViewButton&  viewButton);

    void update (GraphicsCtx& ctx);
};

#endif /* STL_CONTROLLER_MOLECULE */