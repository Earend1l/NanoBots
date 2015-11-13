#include "GameClient.h"

GameClient::GameClient() : m_renderer(m_entities)
{
}

GameClient::~GameClient()
{
}

void GameClient::start()
{
    EntityCreator entityCreator{m_entities, m_entitiesMap,m_physicEngine};
    entityCreator.addEntity(1, 1, 0,  "player");

    PlayerController playerController{*(m_entities.back())};
    EventManager eventManager{m_renderer.getRenderWindow(), playerController};

    MapLoader mapLoader(entityCreator);
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
