#include "ContactListener.h"

ContactListener::ContactListener(GameClient& gameClient) : m_gameClient(gameClient)
{
    //ctor
}

ContactListener::~ContactListener()
{
    //dtor
}

void ContactListener::BeginContact(b2Contact* contact) {

    //Get the b2body
    b2Body* body1 = contact->GetFixtureA()->GetBody();
    EntityAdapter& ent1 = m_gameClient.getEntity(*body1);
    b2Body* body2 = contact->GetFixtureB()->GetBody();
    EntityAdapter& ent2 = m_gameClient.getEntity(*body2);

    ent1.onCollide(ent2);
    ent2.onCollide(ent1);
}

void ContactListener::EndContact(b2Contact* contact) {
  //Get the b2body
  void* b2Body = contact->GetFixtureA()->GetBody();
}
