#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "Entity.h"
#include "EntityManager.h"

class ActionManager
{
    public:
        ActionManager();
        virtual ~ActionManager();
        static void performAction(Entity& sender, Entity& target, int actionID);
    protected:
    private:
};

#endif // ACTIONMANAGER_H
