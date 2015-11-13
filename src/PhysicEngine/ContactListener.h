#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "Box2D/Box2D.h"
#include "EntityAdapter.h"
#include "GameClient.h"

class ContactListener : public b2ContactListener
{
    public:
        ContactListener(GameClient& gameClient);
        virtual ~ContactListener();

        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);

    protected:
    private:
        GameClient& m_gameClient;
};

#endif // CONTACTLISTENER_H
