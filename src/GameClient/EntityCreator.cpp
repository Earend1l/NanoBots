#include "EntityCreator.h"

EntityCreator* EntityCreator::m_instance = new EntityCreator();

EntityCreator::EntityCreator()
{
    //ctor
}

EntityCreator::~EntityCreator()
{
    //dtor
}

void EntityCreator::init(std::vector<EntityAdapter*> *entities, PhysicEngine* physicEngine)
{
    m_entities = entities;
    m_physicEngine = physicEngine;
}

void EntityCreator::addEntity(float positionX, float positionY, float angle, std::string type)
{
    b2Body* body= m_physicEngine->addB2Body(type);
    m_entities->push_back(new EntityAdapter(positionX, positionY, angle, type, body));

}

EntityCreator* EntityCreator::getInstance()
{
    return m_instance;
}
