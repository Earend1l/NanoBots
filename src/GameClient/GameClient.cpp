#include "GameClient.h"

GameClient::GameClient() : m_playerController(), m_renderer(m_entities), m_eventManager(m_renderer.getRenderWindow(), m_playerController, m_entities)
{
    #ifdef DEBUG
        std::cout << __func__ << " called" << std::endl;
    #endif

    EntityCreator::getInstance()->init(&m_entities, &m_physicEngine);
    EntityCreator::getInstance()->addEntity(1, 1, 0,  "player");
}

GameClient::~GameClient()
{
}

void GameClient::start()
{
    MapLoader mapLoader;
    mapLoader.loadMap("data/map.bmp");

    sf::Clock clock;
    clock.restart();
    float time = 0;
    while (running)
    {
        m_physicEngine.update(time);
        running = m_renderer.renderOneFrame();
        m_eventManager.processEvent(time);
        time = clock.restart().asSeconds();
    }
}
