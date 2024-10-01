#include "model.h"

/**************************************************************************/

Model::Model ()
{}

/**************************************************************************/

void Model::addMolecular (Molecular mol)
{
    systemState.moleculars.push_back (mol);
}

void Model::addWall (Wall wall)
{
    systemState.walls.push_back (wall);
}

void Model::update ()
{

    for (int i = 0; i < systemState.moleculars.size(); i++)
    {
        Molecular& mol = systemState.moleculars[i];

        Vector init_speed {mol.speed.getX(),  mol.speed.getY()};
        mol.setCoordShift (init_speed.getX(), init_speed.getY());

        for (int j = i + 1; j < systemState.moleculars.size(); j++)
        {
            Molecular& mol2 = systemState.moleculars[j];
            if ((mol.coord - mol2.coord).getLen() <= mol.size + mol2.size)
            {
                mol.speed.setX  (-mol.speed.getX());
                mol.speed.setY  (-mol.speed.getY());
                mol2.speed.setX (-mol.speed.getX());
                mol2.speed.setY (-mol.speed.getY());
            }
        }
    
        for (int j = 0; j < systemState.walls.size(); j++)
        {
            Wall& wall = systemState.walls[j];
            int len = 0;
            /*-*/
                len = (wall.corner2 - wall.corner1).getLen();
                for (int t = 0; t < len; t++)
                {
                    // расстояние от точки до прямой
                    Vector check = wall.corner1 + (wall.corner2 - wall.corner1) * t / len;
                    if ((mol.coord - check).getLen() <= mol.size)
                    {
                        // printf ("1\n");                                             
                        mol.speed.setY (-mol.speed.getY());
                        break;
                        // mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
                    }
                }
            /*-*/
                len = (wall.corner3 - wall.corner4).getLen();
                for (int t = 0; t < len; t++)
                {
                    // расстояние от точки до прямой
                    Vector check = wall.corner4 + (wall.corner3 - wall.corner4) * t / len;
                    if ((mol.coord - check).getLen() <= mol.size)
                    {
                        // printf ("2\n");
                        mol.speed.setY (-mol.speed.getY());
                        break;
                        // mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
                    }
                }
            /*-*/
                len = (wall.corner4 - wall.corner1).getLen();
                for (int t = 0; t < len; t++)
                {
                    // расстояние от точки до прямой
                    Vector check = wall.corner1 + (wall.corner4 - wall.corner1) * t / len;
                    if ((mol.coord - check).getLen() <= mol.size)
                    {
                        // printf ("3\n");
                        mol.speed.setX (-mol.speed.getX());
                        break;
                        // mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
                    }
                }
            /*-*/
                len = (wall.corner3 - wall.corner2).getLen();
                for (int t = 0; t < len; t++)
                {
                    // расстояние от точки до прямой
                    Vector check = wall.corner2 + (wall.corner3 - wall.corner2) * t / len;
                    if ((mol.coord - check).getLen() <= mol.size)
                    {
                        // // printf ("4\n");
                        mol.speed.setX (-mol.speed.getX());
                        break;
                        // mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
                    }
                }
        }
        mol.setCoordShift (-init_speed.getX(), -init_speed.getY());

        mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
    }
}

/**************************************************************************/
