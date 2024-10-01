#ifndef STL_WALL
#define STL_WALL

#include "object.h"
#include "../vectors/vector.h"

// #include "scene.h"
// #include "../color.h"

class Wall : public Object
{
public:
    Vector corner1;
    Vector corner2;
    Vector corner3;
    Vector corner4;
    // Color    color;

    Wall (             Vector corner1, Vector corner2, Vector corner3, Vector corner4);
    Wall (bool isDraw, Vector corner1, Vector corner2, Vector corner3, Vector corner4);

    virtual ObjectType type () const override;         
    virtual void       draw (GraphicsCtx& ctx) override; // const
}; 

#endif /* STL_WALL */