#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "EntityAdapter.h"
#include "Renderer.h"
#include "PhysicEngine.h"

class GameClient
{
    public:
        GameClient();
        virtual ~GameClient();
        void start();
    protected:
    private:
        std::vector<EntityAdapter> m_entities;
        PhysicEngine *m_physicEngine;
        Renderer *m_renderer;
};

#endif // GAMECLIENT_H
