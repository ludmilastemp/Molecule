#ifndef STL_MODEL_BUTTON
#define STL_MODEL_BUTTON

#include "../../objects/button.h"

class ModelButton
{
public:
    std::vector <Button> buttons;

    ModelButton ();

    void addButton (Button button); 
    void update (GraphicsCtx& ctx);
};

#endif /* STL_MODEL_BUTTON */