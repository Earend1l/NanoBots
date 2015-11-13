#ifndef RACE_H
#define RACE_H

#include "EntityAdapter.h"

class Race
{
    public:
        Race();
        std::shared_ptr<EntityAdapter> createFinishBlock(float positionX, float positionY, float angle, b2Body& body);
        virtual ~Race();
    protected:
    private:
};

#endif // RACE_H
