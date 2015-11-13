#include "GameClient.h"

#include "PlayerController.h"
#include "EventManager.h"
#include "MapLoader.h"
#include "EntityManager.h"


GameClient::GameClient() : m_renderer(m_entities)
{
}

GameClient::~GameClient()
{
}

void GameClient::start()
{
    EntityManager entityManager{m_entities, m_entitiesMap,m_physicEngine};
    entityManager.addEntity(1, 1, 0,  "player");

    PlayerController playerController{*(m_entities.back())};
    EventManager eventManager{m_renderer.getRenderWindow(), playerController};

    MapLoader mapLoader(entityManager);
    mapLoader.loadMap("data/map.bmp");

    sf::Clock clock;
    clock.restart();
    float time = 0;
    while (running)
    {
        m_physicEngine.update(time);
        running = m_renderer.renderOneFrame();
        eventManager.processEvent(time);
        time = clock.restart().asSeconds();
    }
}


EntityAdapter& GameClient::getEntity(b2Body& body)
{
    return *(m_entitiesMap[&body]);
}
