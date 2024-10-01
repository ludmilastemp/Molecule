#ifndef STL_MODEL
#define STL_MODEL

#include "systemState.h"

class Model
{
public:
    SystemState systemState;

    Model ();

    void addMolecular (Molecular mol); 
    void addWall      (Wall      wall); 
    void update ();
};

#endif /* STL_MODEL */