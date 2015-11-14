#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Entity.h"

class PlayerController
{
    public:
        PlayerController(Entity& entity);
        virtual ~PlayerController();

        void move(float valueX, float valueY);
        sf::Vector2f getPosition();

    protected:
    private:
        Entity& m_entity;
};

#endif // PLAYERCONTROLLER_H
