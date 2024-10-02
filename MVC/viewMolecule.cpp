#include "viewMolecule.h"

/**************************************************************************/

ViewMolecule::ViewMolecule (SystemState& init_systemState)
    :systemState (init_systemState)
{}

/**************************************************************************/

void ViewMolecule::update (GraphicsCtx& ctx)
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
