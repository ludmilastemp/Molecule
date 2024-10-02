#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "GrLib/GrLib.h"
#include "MVC/controllerMolecule.h"
#include "MVC/modelMolecule.h"
#include "MVC/viewMolecule.h"

int main()
{
    printf ("Start\n");
    int i = 0;

    GraphicsCtx ctx {};

/*
 * MVC основной (для молекул)
 */
    ModelMolecule      modelMolecule {};
    ViewMolecule       viewMolecule   {modelMolecule.systemState}; 

/*
 * Создание начальных молекул
 */
    modelMolecule.addMolecule ({10, {370, 160}, {2, 4}});
    modelMolecule.addMolecule ({10, {390, 180}, {2, -1}});
    modelMolecule.addMolecule ({10, {410, 200}, {1, -4}});
    modelMolecule.addMolecule ({10, {430, 420}, {5, -3}});
    modelMolecule.addMolecule ({10, {450, 440}, {7, 1}});
    modelMolecule.addMolecule ({10, {400, 440}, {2, 1}});

/*
 * Создание начальных стен
 */
    int diff = 30;
    modelMolecule.addWall ({{300, 275}, {500, 275}, {500, 325}, {300, 325}});
    modelMolecule.addWall ({{100, 100}, {700, 100}, {700, 100 + diff}, {100, 100 + diff}});
    modelMolecule.addWall ({{100, 500 - diff}, {700, 500 - diff}, {700, 500}, {100, 500}});
    modelMolecule.addWall ({{100, 100}, {100 + diff, 100}, {100 + diff, 500}, {100, 500}});
    modelMolecule.addWall ({{700 - diff, 100}, {700, 100}, {700, 500}, {700 - diff, 500}});

/*
 * MVC для кнопок
 */
    ModelButton modelButton {};
    ViewButton  viewButton   {&modelButton.buttons}; 

/*
 * Создание кнопок
 */
    ActionAddMolecule    actionAddMolecule {modelMolecule};
    ActionDeleteMolecule actionDeleteMolecule {modelMolecule};
    modelButton.addButton ({true, {25, 25}, {50, 50}, actionAddMolecule});
    modelButton.addButton ({true, {85, 25}, {50, 50}, actionDeleteMolecule});

    ControllerMolecule controllerMolecule {modelButton, viewButton};

    while (IsWindowOpen(ctx))
    {
        // i++;
        // if (i == 70) return 0;
        
        if (ctx.window.pollEvent(ctx.event))
        {
            ctx.checkEvent = true;
        }

        CheckEventCloseWindow (ctx);
        CleanWindow (ctx);

        /*
        * MVC
        */
            modelMolecule.update ();
            viewMolecule.update (ctx);
            controllerMolecule.update (ctx);

        DisplayWindow(ctx);                                                                                                                                 sf::sleep (sf::seconds(0.01));
    }

    return 0;
}

