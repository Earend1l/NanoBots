#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include <string>
#include <iostream>

class Player : public Entity
{
    public:
        Player(std::string pseudo);
        void onCollide(Entity &Ent2);
        virtual ~Player();
    protected:
    private:
        std::string m_pseudo;

};

#endif // PLAYER_H
