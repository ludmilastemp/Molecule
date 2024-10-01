#ifndef STL_MOLECULAR
#define STL_MOLECULAR

#include "object.h"
#include "../vectors/vector.h"
// #include "scene.h"
// #include "../color.h"

class Molecular : public Object
{
public:
    size_t size;
    Vector coord;
    Vector speed;
    // Color    color;

    Molecular (             size_t size, const Vector& coord, const Vector& speed);
    Molecular (bool isDraw, size_t size, const Vector& coord, const Vector& speed);
      
    void setCoordShift (coord_t x, coord_t y);
    
    virtual ObjectType type () const override;   
    virtual void       draw (GraphicsCtx& ctx) override; // const
}; 

#endif /* STL_MOLECULAR */