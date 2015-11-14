#include "ContactListener.h"
#include "GameClient.h"

ContactListener::ContactListener()
{
    //ctor
}

ContactListener::~ContactListener()
{
    //dtor
}

void ContactListener::BeginContact(b2Contact* contact) {
    //Getting a reference to the game client
    GameClient& gameClient = GameClient::getInstance();

    //Get the concerned entities
    b2Body* body1 = contact->GetFixtureA()->GetBody();
    Entity& ent1 = gameClient.getEntity(body1);
    b2Body* body2 = contact->GetFixtureB()->GetBody();
    Entity& ent2 = gameClient.getEntity(body2);

    //Notify entities of the collision
    ent1.onCollide(ent2);
    ent2.onCollide(ent1);
}

void ContactListener::EndContact(b2Contact* contact) {
  //Get the b2body
  void* b2Body = contact->GetFixtureA()->GetBody();
}
