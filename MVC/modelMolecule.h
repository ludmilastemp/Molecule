#ifndef STL_MODEL_MOLECULE
#define STL_MODEL_MOLECULE

#include "systemState.h"

class ModelMolecule
{
public:
    SystemState systemState;

    ModelMolecule ();

    void operator() ()
    {
        update();
    }

    void deleteMolecule (); 
    void addMolecule    (Molecule mol); 
    void addWall        (Wall      wall); 
    void update ();
};

#endif /* STL_MODEL_MOLECULE */