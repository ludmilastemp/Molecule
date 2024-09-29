#ifndef STL_MODEL
#define STL_MODEL

#include "systemState.h"

class Model
{
public:
    SystemState& systemState;

    Model (SystemState& systemState);

    void update ();
};

#endif /* STL_MODEL */