#include "model.h"

/**************************************************************************/

Model::Model (SystemState& init_systemState)
    :systemState(init_systemState)
{}

/**************************************************************************/

void Model::update ()
{
    for (int i = 0; i < systemState.moleculars.size(); i++)
    {
        Molecular& mol = *systemState.moleculars[i];
        mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
    }
}

/**************************************************************************/
