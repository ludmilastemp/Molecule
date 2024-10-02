#ifndef STL_ACTIONS
#define STL_ACTIONS

#include <cstdlib>
#include "actionClass.h"
#include "../MVC/modelMolecule.h"

/**************************************************************************/

class ActionAddMolecule : public Action
{
private:
    ModelMolecule& modelMolecule;
    
public:

    ActionAddMolecule (ModelMolecule& init_modelMolecule)
        :modelMolecule (init_modelMolecule)
    {}
    
    ActionType type () 
    {
        return ActionTypeAddMolecule;
    }

    virtual void call () override
    {
        int speedX = (int)(((long long)std::rand()) * 15 / RAND_MAX - 7);
        int speedY = (int)(((long long)std::rand()) * 15 / RAND_MAX - 7);
        if (abs(speedX) < 3) speedX = 3;
        if (abs(speedY) < 2) speedY = 2;
        modelMolecule.addMolecule ({10, {370, 380}, {speedX, speedY}});
    };
};

class ActionDeleteMolecule : public Action
{
private:
    ModelMolecule& modelMolecule;
    
public:

    ActionDeleteMolecule (ModelMolecule& init_modelMolecule)
        :modelMolecule (init_modelMolecule)
    {}
    
    ActionType type () 
    {
        return ActionTypeDeleteMolecule;
    }

    virtual void call () override
    {
        modelMolecule.deleteMolecule ();
    };
};


/**************************************************************************/

#endif /* STL_ACTIONS */