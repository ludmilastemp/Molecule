#ifndef STL_MOLECULAR
#define STL_MOLECULAR

#include "object.h"
#include "../vectors/vector.h"
// #include "scene.h"
// #include "../color.h"

class Molecular : public Object
{
public:
    Vector coord;
    Vector speed;
    // Color    color;

    Molecular (             const Vector& coord, const Vector& speed);
    Molecular (bool isDraw, const Vector& coord, const Vector& speed);

    virtual ObjectType type () const override;         
    virtual void       setCoordShift (coord_t x, coord_t y) override;
    virtual void       draw (GraphicsCtx& ctx) override; // const
}; 

#endif /* STL_MOLECULAR */