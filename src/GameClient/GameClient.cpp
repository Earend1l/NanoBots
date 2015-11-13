#include "GameClient.h"

#include "PlayerController.h"
#include "EventManager.h"
#include "MapLoader.h"
#include "EntityManager.h"
#include "Renderer.h"
#include "PhysicEngine.h"

GameClient::GameClient()
{
}

GameClient::~GameClient()
{
}

void GameClient::start()
{
    PhysicEngine physicEngine{*this};
    Renderer renderer{m_entities};
    EntityManager entityManager{m_entities, m_entitiesMap,physicEngine};
    entityManager.addEntity(1, 1, 0,  "player");

    PlayerController playerController{*(m_entities.back())};
    EventManager eventManager{renderer.getRenderWindow(), playerController};

    MapLoader mapLoader{entityManager};
    mapLoader.loadMap("data/map.bmp");

    sf::Clock clock{};
    clock.restart();
    float time = 0;
    while (running)
    {
        physicEngine.update(time);
        running = renderer.renderOneFrame();
        eventManager.processEvent(time);
        time = clock.restart().asSeconds();
    }
}


EntityAdapter& GameClient::getEntity(b2Body& body)
{
    return *(m_entitiesMap[&body]);
}
