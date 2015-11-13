#include "Race.h"

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
}

std::shared_ptr<EntityAdapter> Race::createFinishBlock(float positionX, float positionY, float angle, b2Body& body)
{
     std::shared_ptr<EntityAdapter> finishBlock(new EntityAdapter{positionX, positionY, angle, "finish_block", body});
     finishBlock->addActionOnCollide("player", 1);
     return finishBlock;
}
