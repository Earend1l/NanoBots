#include "EntityManager.h"

EntityManager::EntityManager(std::vector<std::shared_ptr<Entity> > &entities,
                             std::unordered_map <b2Body*, std::shared_ptr<Entity> > &entitiesMap,
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
    //Creating the physical body
    b2Body* body= m_physicEngine.addB2Body(entityName);


    std::shared_ptr<Entity> pentity;
    //Creating the entity
    if (entityCreator entC = m_entityCreators[entityName])
    {
        pentity = std::shared_ptr<Entity>(entC(positionX, positionY, angle, body));
    }
    else
    {
        std::cout << "EntityManager : using default entity constructor for " << entityName << std::endl;
        pentity = std::shared_ptr<Entity>(new Entity(positionX, positionY, angle, std::string (entityName), body));
    }


    //Adding the entity to the map
    m_entities.push_back(pentity);
    m_entitiesMap.insert(std::make_pair<b2Body*, std::shared_ptr<Entity> >(&*body,std::shared_ptr<Entity>(pentity)));
}

void EntityManager::addEntityConstructor(std::string entityName, entityCreator entC)
{
    m_entityCreators.insert(std::make_pair<std::string, entityCreator >(std::string(entityName),entityCreator(entC)));
}
