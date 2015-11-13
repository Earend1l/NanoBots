#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "EntityAdapter.h"

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
        bool running=true;
};

#endif // GAMECLIENT_H
