#include "Player.h"

Player::Player(std::string pseudo) : Entity(1, 1)
{
    m_pseudo = pseudo;
    m_type = "player";
}

void Player::onCollide(Entity *ent2)
{
    if (ent2->getType() == "matter")
    {
        std::cout << "zob" << std::endl;
    }
}

Player::~Player()
{
    //dtor
}
