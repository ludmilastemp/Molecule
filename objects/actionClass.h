#ifndef STL_ACTIONSCLASS
#define STL_ACTIONSCLASS

enum ActionType
{
    ActionTypeAddMolecule,
    ActionTypeDeleteMolecule,
};

class Action // функтор
{
public:

    virtual ~Action () = default;

    void operator() ()
    {
        call();
    }

    virtual ActionType type() = 0;
    virtual void       call() = 0;
};

/**************************************************************************/

#endif /* STL_ACTIONS */