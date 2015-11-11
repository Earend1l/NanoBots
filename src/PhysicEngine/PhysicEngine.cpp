#include "PhysicEngine.h"

using namespace std;

PhysicEngine::PhysicEngine()
{
    b2Vec2 g;
    g.x=0.0;
    g.y=-10.0;
    m_world = new b2World(g);
}

PhysicEngine::~PhysicEngine()
{
    //dtor
    delete m_world;
}

b2Body* PhysicEngine::addB2Body(string entityType)
{
    b2BodyDef bodyDef;
    b2PolygonShape dynamicBox;
    b2Body* b2body;
    float boxX;
    float boxY;
    float density=0.0;
    bodyDef.type = b2_dynamicBody; //default value

    string str;
    string path = "data/entities/" + entityType + "/box2d";
    ifstream file (path.c_str());
    if (file.is_open())
    {
        do
        {
            file >> str;
            if (str=="DYNAMIC_BODY"){
                    bodyDef.type = b2_dynamicBody;
                    density=1;}
            if (str=="STATIC_BODY") {bodyDef.type = b2_staticBody;}
            if (str=="SIZE")
            {
                file  >> boxX;
                file >> boxY;
            }
        } while(str!="END");
        file.close();

        bodyDef.position.Set(0, 0);
        bodyDef.angle=0;
        b2body = m_world->CreateBody(&bodyDef);

        dynamicBox.SetAsBox(boxX, boxY);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = density;
        fixtureDef.friction = 0.2f;
        fixtureDef.restitution =0.3;
        b2body->CreateFixture(&fixtureDef);
    }
    else
        std::cout<<"PhysicEngine : Box2d file not found" << std::endl;


    std::flush(std::cout);

    return b2body;
}

void PhysicEngine::update(float elapsedTime)
{
    m_elapsedTime += elapsedTime;

    while (m_elapsedTime > TIME_GAP)
    {
        m_elapsedTime -= TIME_GAP;
        m_world->Step(TIME_GAP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    }
}
