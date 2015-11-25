#include "ActionManager.h"
#include "GameClient.h"
#include "SFML/Graphics.hpp"

std::unordered_map <std::string, EntityToEntityAction > ActionManager::m_entityToEntityActions;
std::unordered_map <std::string, EntitySpellAction > ActionManager::m_entitySpellActions;

ActionManager::ActionManager()
{
    //ctor
}

ActionManager::~ActionManager()
{
    //dtor
}

void ActionManager::performAction(Entity& sender, Entity& target, int actionID)
{
    if (actionID==1)
    {
        target.setColor(sf::Color(0, 128, 255));
        std::cout << sender.getName() << " :  quelqu'un a gagne ! Je le fous en bleu maggle." << std::endl;
        GameClient::getInstance().getEntityManager().addEntity(0,0, 0, 0, 0, "player");
    }
    else if (actionID==2)
    {
        GameClient::getInstance().getEntityManager().addEntity(target.getPosition().x, target.getPosition().y, target.getAngle(), target.getVelocity().x,target.getVelocity().y, target.getName());
    }
}

void ActionManager::addEntityToEntityAction(std::string actionName, EntityToEntityAction action)
{
    m_entityToEntityActions.insert(std::make_pair<std::string, EntityToEntityAction >(std::string(actionName),EntityToEntityAction(action)));
}

void ActionManager::addEntitySpellAction(std::string actionName, EntitySpellAction action)
{
    m_entitySpellActions.insert(std::make_pair<std::string, EntitySpellAction >(std::string(actionName),EntitySpellAction(action)));
}

void ActionManager::performEntityToEntityAction(std::string actionName, Entity& sender, Entity& target)
{
    EntityToEntityAction action = m_entityToEntityActions[actionName];
    if (action==nullptr)
        std::cout << "ActionManager : unable to find " << actionName << " action" << std::endl;
    else
        action(sender, target);
}

void ActionManager::performEntitySpellAction(std::string actionName, Entity& sender, sf::Vector2f targetPosition)
{
    EntitySpellAction action = m_entitySpellActions[actionName];
    if (action==nullptr)
        std::cout << "ActionManager : unable to find " << actionName << " action" << std::endl;
    else
        action(sender, targetPosition);
}
