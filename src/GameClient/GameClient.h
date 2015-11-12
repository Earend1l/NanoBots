#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "EntityAdapter.h"
#include "Renderer.h"
#include "PhysicEngine.h"
#include "PlayerController.h"
#include "EventManager.h"
#include "MapLoader.h"
#include "EntityCreator.h"


#include <list>

class GameClient
{
    public:
        GameClient();
        virtual ~GameClient();
        void start();
    protected:
    private:
        std::list<EntityAdapter> m_entities;
        PhysicEngine m_physicEngine;
        Renderer m_renderer;
        PlayerController m_playerController;
        EventManager m_eventManager;
        bool running=true;
};

#endif // GAMECLIENT_H
