#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "Entity.h"
#include "EntityManager.h"


//Action function
typedef std::function <void (Entity& sender, Entity& target)> EntityToEntityAction;
typedef std::function <void (Entity& sender, sf::Vector2f targetPosition)> EntitySpellAction;

class ActionManager
{
    public:
        ActionManager();
        virtual ~ActionManager();
        static void addEntityToEntityAction(std::string actionName, EntityToEntityAction action);
        static void performEntityToEntityAction(std::string actionName, Entity& sender, Entity& target);
        static void addEntitySpellAction(std::string actionName, EntitySpellAction action);
        static void performEntitySpellAction(std::string actionName, Entity& sender, sf::Vector2f targetPosition);
        static void performAction(Entity& sender, Entity& target, int actionID);
    protected:
    private:
        static std::unordered_map <std::string, EntityToEntityAction > m_entityToEntityActions;
        static std::unordered_map <std::string, EntitySpellAction > m_entitySpellActions;
};

#endif // ACTIONMANAGER_H
