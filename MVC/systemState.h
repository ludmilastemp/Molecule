#ifndef STL_SYSTEM_STATE
#define STL_SYSTEM_STATE

#include "../objects/molecular.h"
#include "../objects/wall.h"

struct SystemState
{
    std::vector <Molecular> moleculars; 
    std::vector <Wall> walls; 
};

class SystemStateProxy
{
    SystemState& systemState;

public:

    SystemStateProxy (SystemState& init_systemState)
        : systemState(init_systemState)
    {}

    size_t getMolecularsSize () const
    {
        return systemState.moleculars.size();
    }

    Molecular getMolecularIndex (size_t index) const
    {
        return systemState.moleculars[index];
    }

    void DrawMolecularIndex (size_t index, GraphicsCtx& ctx)
    {
        systemState.moleculars[index].draw(ctx);
    }

    size_t getWallsSize () const
    {
        return systemState.walls.size();
    }

    void DrawWallIndex (size_t index, GraphicsCtx& ctx)
    {
        systemState.walls[index].draw(ctx);
    }

};

#endif /* STL_SYSTEM_STATE */