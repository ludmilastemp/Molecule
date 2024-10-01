#ifndef STL_OBJECT
#define STL_OBJECT

#include "../GrLib/GrLibCtx.h"
// #include "../color.h"

using coord_t = int; 

enum ObjectType // enum class
{
    ObjectTypeMolecule,       
    ObjectTypeWall,       
    // ObjectTypeScene,        // содержит группу объектов
};

// enum IsDraw 
// {
// }

class Scene;

class Object
{
public:
    bool isDraw;
    // Scene* scene;

    Object (bool isDraw = 0);
    virtual ~Object () = default; 

    virtual ObjectType type () const = 0;
    virtual void       draw (GraphicsCtx& ctx) = 0; // const
};

#endif /* STL_OBJECT */