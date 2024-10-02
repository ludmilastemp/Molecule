#ifndef STL_BUTTON
#define STL_BUTTON

#include <assert.h>
#include "object.h"
#include "actions.h"
#include "../vectors/vectorDec.h"

class Button : public Object
{
public:
    VectorDec corner;
    VectorDec size;
    // Color color;

    std::vector <Action*> actions; 

    Button (             const VectorDec& corner, const VectorDec& size, Action& action);//, const Color& color);
    Button (bool isDraw, const VectorDec& corner, const VectorDec& size, Action& action);//, const Color& color);
    
    void addAction (Action* action)
    {
        assert (action);
        actions.push_back (action);
    }

    virtual ObjectType type () const override;         
    virtual void       draw (GraphicsCtx& ctx) override; // const                             
};

bool IsButton (const sf::Vector2i& pos, const Button& button);

#endif /* STL_BUTTON */