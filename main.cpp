#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "GrLib/GrLib.h"
#include "MVC/systemState.h"
#include "MVC/model.h"
#include "MVC/view.h"
#include "objects/molecular.h"

//#include "test.h"

int main()
{
    printf ("Start\n");
    int i = 0;

    GraphicsCtx ctx {};
    Molecular mol1 {{320, 300}, {20, 10}};
    Molecular mol2 {{220, 200}, {20, -10}};

    SystemState systemState {};
    systemState.addMolecular (mol1);
    systemState.addMolecular (mol2);

    Model model {systemState};
    View view   {systemState};

    while (IsWindowOpen(ctx))
    {
        i++;
        if (i == 10) return 0;

        CheckEventCloseWindow (ctx);
        CleanWindow (ctx);

        model.update ();
        view.draw (ctx);

        DisplayWindow(ctx);

        sf::sleep (sf::seconds(0.05));
    }

    return 0;
}

