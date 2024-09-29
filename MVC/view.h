#ifndef STL_VIEW
#define STL_VIEW

#include "systemState.h"

class View
{
public:
    SystemState& systemState;

    View (SystemState& systemState);

    void draw (GraphicsCtx& ctx);
};

#endif /* STL_VIEW */