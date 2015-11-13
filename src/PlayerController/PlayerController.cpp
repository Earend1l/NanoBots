#include "PlayerController.h"

PlayerController::PlayerController(EntityAdapter& entity) : m_entity(entity)
{
    //ctor
}

PlayerController::~PlayerController()
{
    //dtor
}

void PlayerController::move(float valueX, float valueY)
{
    m_entity.applyImpulse(valueX*150, valueY*150);
}

sf::Vector2f PlayerController::getPosition()
{
    return m_entity.getPosition();
}
