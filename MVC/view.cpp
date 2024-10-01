#include "view.h"

/**************************************************************************/

View::View (SystemState& init_systemState)
    :systemState (init_systemState)
{}

/**************************************************************************/

void View::draw (GraphicsCtx& ctx)
{
    for (int i = 0; i < systemState.getWallsSize(); i++)
    {
        // Molecular mol = systemState.getMolecularIndex(i);
        // mol.draw (ctx);
        systemState.DrawWallIndex(i, ctx);
    }
    for (int i = 0; i < systemState.getMolecularsSize(); i++)
    {
        // Molecular mol = systemState.getMolecularIndex(i);
        // mol.draw (ctx);
        systemState.DrawMolecularIndex(i, ctx);
    }
}

/**************************************************************************/
