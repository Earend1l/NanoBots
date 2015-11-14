#include "GameClient.h"

#include "PlayerController.h"
#include "EventManager.h"
#include "MapLoader.h"

//TEST : TODO delete
#include "Race.h"

GameClient * GameClient::p_instance = nullptr;

GameClient::GameClient()
{
}

GameClient::~GameClient()
{
}

GameClient::GameClient(const GameClient& rs)
{
    p_instance = rs.p_instance;
}

GameClient& GameClient::operator = (const GameClient& rs)
{
    if (this != &rs) {
        p_instance = rs.p_instance;
    }
       return *this;
}

GameClient& GameClient::getInstance()
{
    static GameClient instance;
    p_instance = &instance;
    return *p_instance;
}

void GameClient::start()
{
    //TEST : TODO delete
    Race::loadMode();

    m_entityManager.addEntity(3, -3, 0,  "player");

    PlayerController playerController{*(m_entities.back())};
    EventManager eventManager{m_renderer.getRenderWindow(), playerController};

    MapLoader mapLoader{m_entityManager};
    mapLoader.loadMap("data/map.bmp");

    sf::Clock clock{};
    clock.restart();
    float time = 0;
    while (running)
    {
        m_physicEngine.update(time);
        eventManager.processEvent(time);
        running = m_renderer.renderOneFrame();
        time = clock.restart().asSeconds();
    }
}


Entity& GameClient::getEntity(b2Body* body)
{
    return *(m_entitiesMap[body]);
}

EntityManager& GameClient::getEntityManager()
{
    return m_entityManager;
}
