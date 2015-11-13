#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "EntityAdapter.h"

class ActionManager
{
    public:
        ActionManager();
        virtual ~ActionManager();
        static void performAction(EntityAdapter& sender, EntityAdapter& target, int actionID);
    protected:
    private:
};

#endif // ACTIONMANAGER_H
