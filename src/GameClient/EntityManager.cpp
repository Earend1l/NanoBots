#include "EntityManager.h"

EntityManager::EntityManager(std::vector<std::shared_ptr<EntityAdapter> > &entities,
                             std::unordered_map <b2Body*, std::shared_ptr<EntityAdapter> > &entitiesMap,
                             PhysicEngine& physicEngine) :
                                 m_entities(entities), m_entitiesMap(entitiesMap),m_physicEngine(physicEngine)
{
}

EntityManager::~EntityManager()
{
    //dtor
}

void EntityManager::addEntity(float positionX, float positionY, float angle, std::string entityName)
{
    b2Body& body= m_physicEngine.addB2Body(entityName);
    std::shared_ptr<EntityAdapter> pentity (new EntityAdapter(positionX, positionY, angle, std::string (entityName), body));
    m_entities.push_back(pentity);
    m_entitiesMap.insert(std::make_pair<b2Body*, std::shared_ptr<EntityAdapter> >(&body,std::shared_ptr<EntityAdapter>(pentity)));
}
