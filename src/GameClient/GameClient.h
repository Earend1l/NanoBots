#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "EntityAdapter.h"
#include "Renderer.h"
#include "PlayerController.h"
#include "EventManager.h"
#include "MapLoader.h"
#include "PhysicEngine.h"
#include "EntityManager.h"


#include <vector>
#include <unordered_map>

class GameClient
{
    public:
        GameClient();
        virtual ~GameClient();
        void start();

        EntityAdapter& getEntity(b2Body& body);

    protected:
    private:
        std::vector<std::shared_ptr<EntityAdapter> > m_entities;
        std::unordered_map <b2Body*, std::shared_ptr<EntityAdapter> > m_entitiesMap;

        PhysicEngine m_physicEngine;
        Renderer m_renderer;
        bool running=true;
};

#endif // GAMECLIENT_H
