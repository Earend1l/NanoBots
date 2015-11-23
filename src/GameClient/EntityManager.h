#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "PhysicEngine.h"
#include <Box2D/Box2D.h>
#include "Entity.h"
#include <vector>
#include <unordered_map>
#include <list>

//Entity creator functions
typedef std::function <std::shared_ptr<Entity> (float positionX, float positionY, float angle, b2Body* body)> entityCreator;

class EntityManager
{
    public:
        EntityManager(std::vector<std::shared_ptr<Entity> > &entities, std::unordered_map <b2Body*, std::shared_ptr<Entity> > &entitiesMap, PhysicEngine& physicEngine);
        virtual ~EntityManager();

        void addEntity(float positionX, float positionY, float angle, std::string entityName);
        void addEntityConstructor(std::string entityName, entityCreator entC);

        void update();
    protected:
    private:
        //Components :
        PhysicEngine &m_physicEngine;

        //vector of all entities created
        std::vector<std::shared_ptr<Entity> > &m_entities;

        //Map used to get entities is constant time using it b2body
        std::unordered_map <b2Body*, std::shared_ptr<Entity> > &m_entitiesMap;

        //Map pairing an entity's name with it constructor
        std::unordered_map <std::string, entityCreator > m_entityCreators;


        struct EntityToCreate {
            float positionX;
            float positionY;
            float angle;
            std::string entityName;
        };
        //List of the entity tot create the next frame
        std::list<EntityToCreate> m_entitiesToCreate;
};

#endif // ENTITYMANAGER_H
