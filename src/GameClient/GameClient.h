#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "Entity.h"

#include <vector>
#include <unordered_map>

#include "PhysicEngine.h"
#include "EntityManager.h"
#include "Renderer.h"

//This class is a singleton
class GameClient
{
    public:
        void start();
        static GameClient& getInstance();

        //Components getter
        EntityManager& getEntityManager();
        Entity& getEntity(b2Body* body);

    protected:
    private:
        //Singleton
        GameClient();
        virtual ~GameClient();
        GameClient(const GameClient& rs);
        GameClient& operator = (const GameClient& rs);

        //Components
        PhysicEngine m_physicEngine;
        Renderer m_renderer{m_entities};
        EntityManager m_entityManager{m_entities, m_entitiesMap,m_physicEngine};


        //Game attributes
        std::vector<std::shared_ptr<Entity> > m_entities;
        std::unordered_map <b2Body*, std::shared_ptr<Entity> > m_entitiesMap;
        bool running=true;

        static GameClient* p_instance;
};

#endif // GAMECLIENT_H
