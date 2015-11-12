#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "PhysicEngine.h"
#include <Box2D/Box2D.h>
#include "EntityAdapter.h"
#include <list>

class EntityCreator
{
    public:
        EntityCreator(std::list<EntityAdapter> &entities, PhysicEngine& physicEngine);
        virtual ~EntityCreator();

        void addEntity(float positionX, float positionY, float angle, std::string type);
    protected:
    private:
        std::list<EntityAdapter> &m_entities;
        PhysicEngine &m_physicEngine;
};

#endif // ENTITYCREATOR_H
