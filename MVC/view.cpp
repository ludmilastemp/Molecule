#include "view.h"

/**************************************************************************/

View::View (SystemState& init_systemState)
    :systemState(init_systemState)
{}

/**************************************************************************/

void View::draw (GraphicsCtx& ctx)
{
    for (int i = 0; i < systemState.moleculars.size(); i++)
    {
        Molecular& mol = *systemState.moleculars[i];
        mol.draw (ctx);
    }
}

/**************************************************************************/
