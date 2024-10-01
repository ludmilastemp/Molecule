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
        // Molecule mol = systemState.getMoleculeIndex(i);
        // mol.draw (ctx);
        systemState.DrawWallIndex(i, ctx);
    }
    for (int i = 0; i < systemState.getMoleculesSize(); i++)
    {
        // Molecule mol = systemState.getMoleculeIndex(i);
        // mol.draw (ctx);
        systemState.DrawMoleculeIndex(i, ctx);
    }
}

/**************************************************************************/
