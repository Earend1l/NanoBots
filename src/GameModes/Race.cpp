#include "Race.h"
#include "GameClient.h"
#include "ActionManager.h"

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

    //Adding entities
    entityManager.addEntityConstructor(std::string("finish_block"), createFinishBlock);
    entityManager.addEntityConstructor(std::string("bullet"), createBullet);

    //Adding actions
    ActionManager::addEntitySpellAction("shootBasicBullet", shootBasicBullet);
}

//Entities
std::shared_ptr<Entity> Race::createFinishBlock(float positionX, float positionY, float angle, b2Body* body)
{
     std::shared_ptr<Entity> finishBlock(new Entity{positionX, positionY, angle, "finish_block", body});
     finishBlock->addActionOnCollide("player", 1);
     return finishBlock;
}

std::shared_ptr<Entity> Race::createBullet(float positionX, float positionY, float angle, b2Body* body)
{
     std::shared_ptr<Entity> finishBlock(new Entity{positionX, positionY, angle, "bullet", body});
     return finishBlock;
}


//Actions
void Race::shootBasicBullet(Entity& caster, sf::Vector2f pos)
{
    GameClient& gameClient = GameClient::getInstance();
    EntityManager& entityManager = gameClient.getEntityManager();

    //Bullet props
    float castRange = 2;
    float speed = 100;
    sf::Vector2f direction = (pos - caster.getPosition());

    //Calculating position and speed vector of the bullet
    //TODO implement faster squareroot
    float norm = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction.x /= norm;
    direction.y /= norm;

    //calculating the angle of the bullet
    float angle = atan2(direction.y, direction.x);

    entityManager.addEntity(caster.getPosition().x + direction.x*castRange,
                            caster.getPosition().y + direction.y*castRange,
                            angle,
                            direction.x*speed,
                            direction.y*speed, "bullet");
}
