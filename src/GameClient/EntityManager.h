#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "PhysicEngine.h"
#include <Box2D/Box2D.h>
#include "EntityAdapter.h"
#include <vector>
#include <unordered_map>

class EntityManager
{
    public:
        EntityManager(std::vector<std::shared_ptr<EntityAdapter> > &entities, std::unordered_map <b2Body*, std::shared_ptr<EntityAdapter> > &entitiesMap, PhysicEngine& physicEngine);
        virtual ~EntityManager();

        void addEntity(float positionX, float positionY, float angle, std::string type);
    protected:
    private:
        std::vector<std::shared_ptr<EntityAdapter> > &m_entities;
        std::unordered_map <b2Body*, std::shared_ptr<EntityAdapter> > &m_entitiesMap;
        PhysicEngine &m_physicEngine;
};

#endif // ENTITYMANAGER_H
