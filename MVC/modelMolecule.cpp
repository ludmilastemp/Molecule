#include "modelMolecule.h"

/**************************************************************************/

ModelMolecule::ModelMolecule ()
{}

/**************************************************************************/

void CollideWithMolecules (SystemState& systemState, Molecule& mol, int index);
void CollideWithWalls (SystemState& systemState, Molecule& mol);

/**************************************************************************/

void ModelMolecule::addMolecule (Molecule mol)
{
    systemState.molecules.push_back (mol);
}

void ModelMolecule::deleteMolecule ()
{
    if (systemState.molecules.size() > 0)
        systemState.molecules.pop_back ();
}

void ModelMolecule::addWall (Wall wall)
{
    systemState.walls.push_back (wall);
}

void ModelMolecule::update ()
{
    for (int i = 0; i < systemState.molecules.size(); i++)
    {
        Molecule& mol = systemState.molecules[i];

        Vector init_speed {mol.speed.getX(),  mol.speed.getY()};
        mol.setCoordShift (init_speed.getX(), init_speed.getY());

        CollideWithMolecules (systemState, mol, i);
        CollideWithWalls     (systemState, mol);
    
        mol.setCoordShift (-init_speed.getX(), -init_speed.getY());
        mol.setCoordShift (mol.speed.getX(), mol.speed.getY());
    }
}

void CollideWithMolecules (SystemState& systemState, Molecule& mol, int i)
{
    for (int j = i + 1; j < systemState.molecules.size(); j++)
    {
        Molecule& mol2 = systemState.molecules[j];
        if ((mol.coord - mol2.coord).getLen() <= mol.size + mol2.size)
        {
            mol.speed.setX  (-mol.speed.getX());
            mol.speed.setY  (-mol.speed.getY());
            mol2.speed.setX (-mol.speed.getX());
            mol2.speed.setY (-mol.speed.getY());
        }
    }
}

void CollideWithWalls (SystemState& systemState, Molecule& mol)
{
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
                    mol.speed.setY (-mol.speed.getY());
                    break;
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
                    mol.speed.setY (-mol.speed.getY());
                    break;
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
                    mol.speed.setX (-mol.speed.getX());
                    break;
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
                    mol.speed.setX (-mol.speed.getX());
                    break;
                }
            }
    }
}

/**************************************************************************/
