#ifndef RACE_H
#define RACE_H

#include "Entity.h"

class Race
{
    public:
        Race();
        virtual ~Race();
        static void loadMode();

        //Entities
        static std::shared_ptr<Entity> createFinishBlock(float positionX, float positionY, float angle, b2Body* body);
        static std::shared_ptr<Entity> createBullet(float positionX, float positionY, float angle, b2Body* body);

        //Actions
        static void shootBasicBullet(Entity& caster, sf::Vector2f pos);
    protected:
    private:
};

#endif // RACE_H
