#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "EntityAdapter.h"

class PlayerController
{
    public:
        PlayerController(EntityAdapter& entity);
        virtual ~PlayerController();

        void move(float valueX, float valueY);

    protected:
    private:
        EntityAdapter& m_entity;
};

#endif // PLAYERCONTROLLER_H
