#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "GrLib/GrLib.h"
#include "MVC/systemState.h"
#include "MVC/model.h"
#include "MVC/view.h"
#include "objects/molecule.h"

//#include "test.h"

int main()
{
    printf ("Start\n");
    int i = 0;

    GraphicsCtx ctx {};

    Model model {};
    View view   {model.systemState}; 

    model.addMolecule ({10, {370, 160}, {2, 4}});
    model.addMolecule ({10, {390, 180}, {2, -1}});
    model.addMolecule ({10, {410, 200}, {1, -4}});
    model.addMolecule ({10, {430, 420}, {5, -3}});
    model.addMolecule ({10, {450, 440}, {7, 1}});
    model.addMolecule ({10, {400, 440}, {2, 1}});

    int diff = 30;
    model.addWall ({{300, 275}, {500, 275}, {500, 325}, {300, 325}});
    model.addWall ({{100, 100}, {700, 100}, {700, 100 + diff}, {100, 100 + diff}});
    model.addWall ({{100, 500 - diff}, {700, 500 - diff}, {700, 500}, {100, 500}});
    model.addWall ({{100, 100}, {100 + diff, 100}, {100 + diff, 500}, {100, 500}});
    model.addWall ({{700 - diff, 100}, {700, 100}, {700, 500}, {700 - diff, 500}});


    while (IsWindowOpen(ctx))
    {
        i++;
        // if (i == 70) return 0;

        model.update ();

        CheckEventCloseWindow (ctx);
        CleanWindow (ctx);

        view.draw (ctx);

        DisplayWindow(ctx);

        sf::sleep (sf::seconds(0.01));
    }

    return 0;
}

