#include "ContactListener.h"

ContactListener::ContactListener()
{
    //ctor
}

ContactListener::~ContactListener()
{
    //dtor
}

void ContactListener::BeginContact(b2Contact* contact) {

  //Get the b2body
  void* b2Body = contact->GetFixtureA()->GetBody();
}

void ContactListener::EndContact(b2Contact* contact) {
  //Get the b2body
  void* b2Body = contact->GetFixtureA()->GetBody();

}
