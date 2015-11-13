#include "ActionManager.h"

ActionManager::ActionManager()
{
    //ctor
}

ActionManager::~ActionManager()
{
    //dtor
}

void ActionManager::performAction(EntityAdapter& sender, EntityAdapter& target, int actionID)
{
    std::cout << sender.getName() << " : OUI EUH je lance a " << target.getName() << " l'action " << actionID << std::endl;
}
