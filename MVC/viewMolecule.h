#ifndef STL_VIEW_MOLECULE
#define STL_VIEW_MOLECULE

#include "systemState.h"

class ViewMolecule
{
public:
    SystemStateProxy systemState;

    ViewMolecule (SystemState& systemState);

    void operator() (GraphicsCtx& ctx)
    {
        update(ctx);
    }

    void update (GraphicsCtx& ctx);
};

#endif /* STL_VIEW_MOLECULE */