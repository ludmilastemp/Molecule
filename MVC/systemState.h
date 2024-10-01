#ifndef STL_SYSTEM_STATE
#define STL_SYSTEM_STATE

#include "../objects/molecule.h"
#include "../objects/wall.h"

struct SystemState
{
    std::vector <Molecule> molecules; 
    std::vector <Wall> walls; 
};

class SystemStateProxy
{
    SystemState& systemState;

public:

    SystemStateProxy (SystemState& init_systemState)
        : systemState(init_systemState)
    {}

    size_t getMoleculesSize () const
    {
        return systemState.molecules.size();
    }

    Molecule getMoleculeIndex (size_t index) const
    {
        return systemState.molecules[index];
    }

    void DrawMoleculeIndex (size_t index, GraphicsCtx& ctx)
    {
        systemState.molecules[index].draw(ctx);
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