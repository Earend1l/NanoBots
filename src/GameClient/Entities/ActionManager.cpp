#include "ActionManager.h"
#include "GameClient.h"
#include "SFML/Graphics.hpp"

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
    }

        //Impossible de créer un objet durant une step du moteur physique !
        //GameClient::getInstance().getEntityManager().addEntity(3, 3, 0, "player");
}
