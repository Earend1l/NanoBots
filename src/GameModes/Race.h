#ifndef RACE_H
#define RACE_H

#include "Entity.h"

class Race
{
    public:
        Race();
        virtual ~Race();
        static void loadMode();

        static std::shared_ptr<Entity> createFinishBlock(float positionX, float positionY, float angle, b2Body* body);
    protected:
    private:
};

#endif // RACE_H
