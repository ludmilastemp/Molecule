#ifndef STL_SYSTEM_STATE
#define STL_SYSTEM_STATE

#include "../objects/molecular.h"

class SystemState
{
public:
    std::vector <Molecular*> moleculars;

    SystemState ();

    void addMolecular (Molecular& mol);
};

#endif /* STL_SYSTEM_STATE */