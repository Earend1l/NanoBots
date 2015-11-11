#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "Entity.h"
#include "GameClient.h"
#include "PhysicEngine.h"
#include <Box2D/Box2D.h>

class EntityCreator
{
    public:
        static EntityCreator* getInstance();
        void init(std::vector<EntityAdapter*> *m_entities, PhysicEngine* physicEngine);
        void addEntity(float positionX, float positionY, float angle, std::string type);
        static EntityCreator* GetInstance();
    protected:
    private:
        EntityCreator();
        virtual ~EntityCreator();

        static EntityCreator* m_instance;

        std::vector<EntityAdapter*> *m_entities;
        PhysicEngine *m_physicEngine;
};

#endif // ENTITYCREATOR_H
