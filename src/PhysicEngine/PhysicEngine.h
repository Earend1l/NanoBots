#ifndef PHYSICENGINE_H
#define PHYSICENGINE_H

#include <Box2D/Box2D.h>
#include <fstream>
#include <iostream>
#include <string>


#define TIME_GAP 1.0/60.0
#define VELOCITY_ITERATIONS 12
#define POSITION_ITERATIONS 4

class PhysicEngine
{
    public:
        PhysicEngine();
        virtual ~PhysicEngine();
        b2Body* addB2Body(std::string entity);
        void update(float elapsedTime);

    protected:
    private:
        b2World *m_world;
        float m_elapsedTime;

};

#endif // PHYSICENGINE_H
