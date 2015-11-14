#include "Race.h"
#include "GameClient.h"

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
}

void Race::loadMode()
{
    GameClient& gameClient = GameClient::getInstance();
    EntityManager& entityManager = gameClient.getEntityManager();

    entityManager.addEntityConstructor(std::string("finish_block"), createFinishBlock);
}

std::shared_ptr<Entity> Race::createFinishBlock(float positionX, float positionY, float angle, b2Body* body)
{
     std::shared_ptr<Entity> finishBlock(new Entity{positionX, positionY, angle, "finish_block", body});
     finishBlock->addActionOnCollide("player", 1);
     return finishBlock;
}
